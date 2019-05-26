#include <iostream>
#include <armadillo>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include "metrics/metric.h"
#include "metrics/levelSpacings.h"
#include "resultFinder.h"
#include "runSim1D.h"
#include "metrics/avgEigVec.h"
#include "metrics/utils.h"
#include "metrics/inversePR.h"
#include "metrics/aboutRun.h"
#include "JComputer.h"
#include "JComputerFactory.h"
#include "metrics/energyLevels.h"

using namespace std;
using namespace arma;


int main(int argc, char** argv){

	// set variables, using command line args if applicable
	double W = 5;
	int numSites = 3;
	int iterations = 10;
	int MAXT = 3;
	if (argc > 1){
		W = stoi(argv[1]);
	}
	if (argc > 2){
		numSites = stoi(argv[2]);
	}
	if (argc > 3){
		iterations = stoi(argv[3]);
	}
	if (argc > 4){
		MAXT = stoi(argv[4]);
	}
	// how are we computing j?

	JComputerFactory::Funs fun = JComputerFactory::Funs::LorentzT;
	double t = 10;
	double gamma = 1;
	int nnOnly = 0;

	JComputerFactory factory = JComputerFactory();
	JComputer jComputer = factory.computeJ(fun, t,nnOnly,gamma);
	// set up metrics
	vector<metric*> metrics;
	metrics.push_back(new LevelSpacings());
	metrics.push_back(new AvgEigVec());
	//metrics.push_back(new EnergyLevels());
	//metrics.push_back(new InversePR());
	ResultFinder rf = ResultFinder(metrics);

	string jMethod = jComputer.methodDesc();
	AboutRun about = AboutRun(W,MAXT,numSites,iterations,jMethod);

	for (int i = 0; i< iterations; i++ ){
		mat A(numSites,numSites);
		runSim1D(W, numSites,A,jComputer);
		rf.saveResults(A, iterations);
	}
	about.printResult();
	rf.printResults();

	return 0;
}

#include <iostream>
#include <armadillo>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include "sixMat.h"
#include "runSim.h"
#include "metric.h"
#include "levelSpacings.h"
#include "resultFinder.h"
#include "runSim1D.h"
#include "avgEigVec.h"
#include "utils.h"
#include "inversePR.h"
#include "aboutRun.h"
#include "computeJ.h"

using namespace std;
using namespace arma;

// TODO: Refactor this
int MAXT = 3;

int main(int argc, char** argv){

	// set variables, using command line args if applicable
	double W = 5;
	int numSites = 3;
	int iterations = 10;
	if (argc > 1){
		W = stoi(argv[1]);
	}
	if (argc > 2){
		numSites = stoi(argv[2]);
	}
	if (argc > 3){
		iterations = stoi(argv[3]);
	}
	// how are we computing j?

	ComputeJ jComputer(MAXT, ComputeJ::Funs::uniRandT,1);

	// set up metrics
	vector<metric*> metrics;
	metrics.push_back(new LevelSpacings());
	metrics.push_back(new AvgEigVec());
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

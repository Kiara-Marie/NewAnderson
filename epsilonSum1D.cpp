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

using namespace std;
using namespace arma;


int main(int argc, char** argv){
	// set variables
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
	vector<metric*> metrics;
	metrics.push_back(new LevelSpacings());
	ResultFinder rf = ResultFinder(metrics);

	for (int i = 0; i< iterations; i++ ){
		mat A(numSites,numSites);
		runSim1D(W, numSites,A);
		rf.saveResults(A);
	}

	rf.printResults();

	return 0;
}
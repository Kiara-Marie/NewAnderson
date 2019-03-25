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

using namespace std;
using namespace arma;

int MAXT = 3;

double findT(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (j > 0.00001){
		return p;
	} else return 0;
}
double findTNN(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (xi -xj > 1){
		return 0;
	}
	if (j > 0.00001){
		return p;
	} else return 0;

}

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
	metrics.push_back(new AvgEigVec());
	metrics.push_back(new InversePR());
	ResultFinder rf = ResultFinder(metrics);

	for (int i = 0; i< iterations; i++ ){
		mat A(numSites,numSites);
		runSim1D(W, numSites,A,findT);
		rf.saveResults(A, iterations);
		if (i==5){
			cout<<"Example matrix\n";
			A.print();
		}
	}

	rf.printResults();

	return 0;
}

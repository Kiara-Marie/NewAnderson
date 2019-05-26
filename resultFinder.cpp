#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metrics/metric.h"
#include "resultFinder.h"
using namespace std;
using namespace arma;

ResultFinder::ResultFinder(vector<metric*> metrics){
	this->metrics = metrics;
}

void ResultFinder::saveResults(mat& A, int iterations){
	vec eigval;
	mat eigvec;
	eig_sym( eigval, eigvec, A );
	vec applyA = A * eigvec.col(0);
	//applyA.print("First eigval multiplied by A\n");
	vec byFactor = eigvec.col(0) * eigval(0);
	//byFactor.print("First eigvec multiplied by first eigval\n");
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->save(eigval, eigvec, A, iterations);
	}
}

void ResultFinder::printResults(){
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->printResult();
	}
}

#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "resultFinder.h"
using namespace std;
using namespace arma;

ResultFinder::ResultFinder(vector<metric*> metrics){
	this->metrics = metrics;
}

// Save all the results
void ResultFinder::saveResults(mat& A, int iterations){
	vec eigval;
	mat eigvec;
	eig_sym( eigval, eigvec, A );
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->save(eigval, eigvec, A, iterations);
	}
}

// Tell all metrics to print results
void ResultFinder::printResults(){
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->printResult();
	}
}

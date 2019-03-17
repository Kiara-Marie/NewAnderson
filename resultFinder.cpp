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

void ResultFinder::saveResults(mat& A, int iterations){
	vec eigval;
	mat eigvec;
	eig_sym( eigval, eigvec, A );
	for (int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->save(eigval, eigvec, A, iterations);
	}
}

void ResultFinder::printResults(){
	for (int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->printResult();
	}
}

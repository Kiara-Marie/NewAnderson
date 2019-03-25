#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "inversePR.h"
using namespace std;
using namespace arma;

void InversePR::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){

	if (this-> iterations == 0){
		this->iterations = iterations;
	} else if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}

	// squared = eigvecs^2
	mat squared = pow(eigvec,2);
	// mags = |eigvecs|^2
	mat mags = cumsum(squared);
	// mags = |eigvecs|^4
	mags = pow(mags,2);
	double ipr = cumsum(mags,1);
	ipr = 1/ipr;

	
	return;

}

void InversePR::printResult(){

	return;
}

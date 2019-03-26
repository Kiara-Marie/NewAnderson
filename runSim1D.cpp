#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "computeJ.h"
using namespace arma;
using namespace std;

int is_symmetric(const mat& A){
	if (A.n_rows != A.n_cols){
		return 0;
	}
	for (unsigned int i = 0; i< A.n_rows;i++){
		for (unsigned int j = 0; j<A.n_cols;j++){
			if(A(i,j) != A(j,i)){
				return 0;
			}
		}
	}
	return 1;
}

void runSim1D(double W, int length, mat& A, ComputeJ jComputer){
	// make random
	arma_rng::set_seed_random();

	// set up

	vec energies = randu<vec>(length);
	energies = energies * W;
	vec toRmv = ones(length);
	toRmv = toRmv * W/2;
	energies = energies - toRmv;
	double eSum = sum(energies);
	energies = energies *2;

	toRmv = toRmv / W/2;
	toRmv = toRmv * eSum;
	energies = energies - toRmv;


	A.diag() = energies;
	double t = 1;
	for (int xi = 0; xi<length;xi++){
		for (int xj = 0; xj<length; xj++){
			if(xi == xj) {
				continue;
			}
			t = jComputer.jFinder(xi,xj);
			A(xi, xj) = t;
			A(xj, xi) = t;
			}
		}
	if(!is_symmetric(A)){
		cerr<<"Matrix Not Hermitian!\n";
	}
	return;
}

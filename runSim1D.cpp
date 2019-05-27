#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
#include "findE.h"
#include "runSim1D.h"
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

void runSim1D(double W, int length, mat& A, JComputer& jComputer){

	if (W==0){
	cerr<<"W was zero\n";
	}

	vec energies = zeros(length);
	getEnergies(length, energies, W);

	A.diag() = energies;
	if (jComputer.needsEnergy){
		jComputer.additionalInfo(energies);
	}
	double j = 1;
	for (int xi = 0; xi<length;xi++){
		for (int xj = 0; xj<length; xj++){
			if(xi == xj) {
				continue;
			}
			j = jComputer.jFinder(xi,xj);
			A(xi, xj) = j;
			A(xj, xi) = j;
			}
		}
	//A.print();
	if(!is_symmetric(A)){
		cerr<<"Matrix Not Hermitian!\n";
	}
	return;
}

void getEnergies(int length, vec& energies, double W){
	// make random
	//arma_rng::set_seed_random();

	// set up
	vec nValues = randu<vec>(length) * W;
	nValues.transform( [](double val) { return round(val); } );

	 // generate a vector of values between 0 and 1, then multiply element-wise
	 // by n
	vec lValues = randu<vec>(length) % nValues ;
	lValues.transform( [](double val) { return floor(val); } );

	for (int i = 0; i < length; i++){
		char nc = (char) nValues(i);
		char lc = (char) lValues(i);

		energies(i) = bindingEnergy(nc,lc);
	}

	nValues.print("n values\n");
	lValues.print("l values\n");
	energies.print("energies\n");


}

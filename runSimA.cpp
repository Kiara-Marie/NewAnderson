#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <random>
#include "jComputer.h"
#include "findE.h"
#include "runSimA.h"
#include "runSim1D.h"
using namespace arma;
using namespace std;

double MAXJUMP = 1;

void runSimA(double W, int length, mat& A, JComputer& jComputer){

	if (W==0){
	cerr<<"W was zero\n";
	}

	vec energies = zeros(length);
	getEnergiesA(length, energies, W);

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

void getEnergiesA(int length, vec& energies, double W){
	// make random
	arma_rng::set_seed_random();
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,MAXJUMP);

	// set up
	vec nValues = randu<vec>(length) * W;
	nValues.transform( [](double val) { return ceil(val) + 1; } );

	 // generate a vector of values between 0 and 1, then multiply element-wise
	 // by n
	vec lValues = randu<vec>(length) % nValues ;
	lValues.transform( [](double val) { return floor(val); } );

	for (int i = 0; i < length; i++){
		char nc = (char) nValues(i);
		char lc = (char) lValues(i);

		double delta =  distribution(generator);

		double lower = bindingEnergy(nc,lc);
		double upper = bindingEnergy(nc+delta, lc+1);
		if ((lower - upper) > 2){
			cout<<"lower = "<<lower<<", upper = "<<upper<<", n ="<<nValues(i)<<", delta = "<<delta<<"\n";
		}
		energies(i) = lower - upper;
	}

	//nValues.print("n values\n");
	//lValues.print("l values\n");
	//energies.print("energies\n");

}

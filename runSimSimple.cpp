#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
#include "runSim1D.h"
#include "runSimSimple.h"

using namespace arma;
using namespace std;

void runSimSimple(double W, int length, mat& A, JComputer& jComputer){
	// make random
	arma_rng::set_seed_random();

	// set up
	vec energies = randu<vec>(length);
	if (W != 0){
		energies = energies * W;
		vec toRmv = ones(length);
		toRmv = toRmv * W/2;
		energies = energies - toRmv;
		double eSum = sum(energies);
		energies = energies *2;

		toRmv = toRmv / W/2;
		toRmv = toRmv * eSum;
		energies = energies - toRmv;
	} else {
		energies.ones() * 2;
	}
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

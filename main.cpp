#include <iostream>
#include <armadillo>
#include <cmath>
#include <string>
#include "sixMat.h"

using namespace std;
using namespace arma;

int main(int argc, char** argv){
	// make random
	//arma_rng::set_seed_random();

	// set variables
	double W = 5;
	int length = 3;
	double t = 1;
	if (argc > 1){
		W = stoi(argv[1]);
	}
	if (argc > 2){
		numSites = stoi(argv[2]);
	}
	// set up
	SixMat A = SixMat(length);
	vec energies = randu<vec>(pow(length));
	energies = energies * W;
	A.diag(energies);
	for (int zi = 0; zi<length-1;zi++){
		for (int yi = 0; yi<length-1;yi++){
			for (int xi = 0; xi<length-1;xi++){
				A.set(xi, yi, zi, xi+1, yi, zi, t);
				A.set(xi, yi, zi, xi, yi+1, zi, t);
				A.set(xi, yi, zi, xi, yi, zi+1, t);
			}
		}
	}
	A.print("A: ");
	vec eigval = A.eigs(numSites-1);
	eigval.print("Eigenvalues: ");

	return 0;
}

#include <iostream>
#include <armadillo>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include "sixMat.h"

void runSim(double W, int length, double t, SixMat* A){
	// make random
	arma_rng::set_seed_random();

	// set up
	vec energies = randu<vec>(pow(length,3));
	energies = energies * W;
	A->diag(energies);
	for (int zi = 0; zi<length-1;zi++){
		for (int yi = 0; yi<length-1;yi++){
			for (int xi = 0; xi<length-1;xi++){
				A->set(xi, yi, zi, xi+1, yi, zi, t);
				A->set(xi, yi, zi, xi, yi+1, zi, t);
				A->set(xi, yi, zi, xi, yi, zi+1, t);
			}
		}
	}
	return;
}
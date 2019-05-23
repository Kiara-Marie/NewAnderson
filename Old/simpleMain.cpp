#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char** argv){
	// make random
	//arma_rng::set_seed_random();
	// set variables
	double W = 5;
	int numSites = 7;
	double t = 1;
	if (argc > 1){
		W = stoi(argv[1]);
	}
	if (argc > 2){
		numSites = stoi(argv[2]);
	}
	// set up
	SpMat<double> A(numSites,numSites);
	//mat A(numSites,numSites);
	A.zeros();
	vec energies = randu<vec>(numSites);
	energies = energies * W;
	A.diag() = energies;
	for (int i = 0; i<numSites-1;i++){
		A(i+1, i) = t;
		A(i, i+1) = t;
	}
	A.print("A: ");
	vec eigval = eigs_sym(A, numSites-1);
	vec smallestEigVal = eigs_sym(A, 1,"sm");
	//vec eigval = eig_sym(A);
	eigval.print("Eigenvalues: ");
	smallestEigVal.print("smallestEigVal: ");


	return 0;
}

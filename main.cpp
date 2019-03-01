#include <iostream>
#include <armadillo>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include "sixMat.h"
#include "runSim.h"

using namespace std;
using namespace arma;

int main(int argc, char** argv){
	// set variables
	double W = 5;
	int length = 3;
	double t = 1;
	int iterations = 10;

	if (argc > 1){
		W = stoi(argv[1]);
	}
	if (argc > 2){
		length = stoi(argv[2]);
	}
	if (argc > 3){
		iterations = stoi(argv[3]);
	}

	for (int i = 0; i< iterations; i++ ){
		SixMat A = SixMat(length);
		runSim(W, length, t,&A);
		saveResults(A);
	}

	printResults();

	return 0;
}

// TODO
void saveResults(SixMat& A){
	return;
}

// TODO
void printResults(){
	cout<<"Not implemented\n";
	return;
}

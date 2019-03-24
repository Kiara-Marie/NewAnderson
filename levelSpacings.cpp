#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "metric.h"
#include "levelSpacings.h"
#include "utils.h"
using namespace std;
using namespace arma;

void LevelSpacings::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){
	if (this->avgENPrime.n_elem == 0){
		this->avgENPrime = zeros(eigval.n_elem);
	} else if (this->avgENPrime.n_elem != eigval.n_elem){
		cerr<<"Inconsistent number of eigenvalues!\n";
	}

	if (this-> iterations == 0){
		this->iterations = iterations;
	} else if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}

	double up;
	double down;

	for(unsigned int i = 1; i<eigval.n_elem-1; i++){
		up = eigval(i+1) - eigval(i);
		down = eigval(i) - eigval(i - 1);
		this->spacings.push_back(up);
		this->avgENPrime(i) += up/down;
	}
	return;
}

void LevelSpacings::printResult(){
	ostream spacingsFile(NULL);
	char toAdd[] = "-spacings.csv";
	string stupid = getDate();
	string moreStupid = getTime();
	getFile(&spacingsFile,toAdd);
	spacingsFile<<"All Spacings:\n";
	for (unsigned int i = 1; i< spacings.size(); i++){
			spacingsFile<<spacings[i]<< ", ";
	}
/*
	ostream* ENFile;
	toAdd = "-EnPrime.txt";
	ENFile = getFile(toAdd);
	this->avgENPrime = this->avgENPrime / iterations;
	*(ENFile)<<"Average En' between levels: \n";
	avgENPrime.print(*(ENFile));

*/
	return;
}

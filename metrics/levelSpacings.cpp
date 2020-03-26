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

unsigned long MAX_TO_SAVE = 16384;
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
	unsigned int numToSave = eigval.n_elem-2;
	for(unsigned int i = 1; i<=numToSave; i++){
		up = eigval(i+1) - eigval(i);
		down = eigval(i) - eigval(i - 1);
		this->spacings.push_back(up);
		// cout<<"eigval i - 1 = "<<eigval(i - 1)<<"eigval i = "<<eigval(i)<<"eigval i + 1 = "<<eigval(i+1)<<"\n";
		// double EnPrime = up/down < 1 ? up/down : down/up;
		// cout<<"EnPrime = "<<EnPrime<<"\n";
		this->avgENPrime(i) += up/down < 1 ? up/down : down/up;
	}
	return;
}

void LevelSpacings::printResult(){
	this->printS();
	this->printENPrime();
	return;
}

void LevelSpacings::printS(){
	ostream file(NULL);
	char toAdd[] = "-spacings.csv";

	filebuf fileBuffer;
	string fileName = getDate();
	fileName.append(getSeconds());
	fileName.append(toAdd);
	fileBuffer.open(fileName,ios_base::out);
	file.rdbuf(&fileBuffer);
	unsigned int numToSave = min(spacings.size(), MAX_TO_SAVE);
	double rsf = 0;
	for (unsigned int i = 1; i< numToSave; i++){
			rsf += spacings[i];
			file<<spacings[i]<< ", ";
	}
	double m = rsf/numToSave;
	printf("Average spacing = %f\n", m );

}

void LevelSpacings::printENPrime(){
	ostream file(NULL);
	char toAdd[] = "-EnPrime.csv";
	filebuf fileBuffer;
	string fileName = getDate();
	fileName.append(getSeconds());
	fileName.append(toAdd);
	fileBuffer.open(fileName,ios_base::out);
	file.rdbuf(&fileBuffer);

	this->avgENPrime = this->avgENPrime / iterations;
	//ENFile<<"Average En' between levels: \n";
	avgENPrime.save(file,csv_ascii);
}

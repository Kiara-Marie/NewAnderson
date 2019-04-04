#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "avgEigVec.h"
#include "utils.h"
using namespace std;
using namespace arma;

void AvgEigVec::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){
	if (this->avgMat.n_elem == 0){
		this->avgMat = zeros(eigvec.n_rows, eigvec.n_cols);
	} else if (this->avgMat.n_elem != eigvec.n_elem){
		cerr<<"Inconsistent number of eigenvectors!\n";
	}
	if (this-> iterations == 0){
		this->iterations = iterations;
	} else if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}
	this->avgMat = this->avgMat + eigvec;
}

void AvgEigVec::printResult(){

	ostream file(NULL);
	char toAdd[] = "-AverageEigenVectors.csv";

	filebuf fileBuffer;
	string fileName = getDate();
	fileName.append(getSeconds());
	fileName.append(toAdd);
	fileBuffer.open(fileName,ios_base::out);
	file.rdbuf(&fileBuffer);

	this->avgMat = this->avgMat / iterations;
	this->avgMat.save(file,csv_ascii);

	return;
}

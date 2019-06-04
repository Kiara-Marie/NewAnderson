#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "inversePR.h"
#include "utils.h"
using namespace std;
using namespace arma;

void InversePR::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){

	if (this-> iterations == 0){
		this->iterations = iterations;
	} else if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}

	// raise every element to the fourth power
	mat tesseract = pow(eigvec,4);
	mat cumulative = cumsum(mags,0);
	cout<<"Cumulative sum of rows in eigenvector matrix\n";
	cumulative.print();
	double ipr = cumulative(0,0);
	ipr = 1/ipr;

	this->iprs.push_back(ipr);
	return;

}

void InversePR::printResult(){
	ostream file(NULL);
	char toAdd[] = "-InversePR.csv";

	filebuf fileBuffer;
	string fileName = getDate();
	fileName.append(getSeconds());
	fileName.append(toAdd);
	fileBuffer.open(fileName,ios_base::out);
	file.rdbuf(&fileBuffer);

	for (unsigned int i = 1; i< iprs.size(); i++){
			file<<iprs[i]<< ", ";
	}
	return;
}

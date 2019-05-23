#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "metric.h"
#include "energyLevels.h"
#include "utils.h"

using namespace std;
using namespace arma;

void EnergyLevels::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){
	if (this-> iterations == 0){
		this->iterations = iterations;
	} else if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}

	double e;
	unsigned int numToSave = eigval.n_elem-1;
	for(unsigned int i = 0; i<numToSave; i++){
		e = eigval(i);
		this->energies.push_back(e);
	}
	return;
}

void EnergyLevels::printResult(){
	unsigned long MAX_TO_SAVE = 16384;
	ostream file(NULL);
	char toAdd[] = "-energies.csv";

	filebuf fileBuffer;
	string fileName = getDate();
	fileName.append(getSeconds());
	fileName.append(toAdd);
	fileBuffer.open(fileName,ios_base::out);
	file.rdbuf(&fileBuffer);
	unsigned int numToSave = min(energies.size(), MAX_TO_SAVE);
	double rsf = 0;
	for (unsigned int i = 1; i< numToSave; i++){
			rsf += energies[i];
			file<<energies[i]<< ", ";
	}
	double m = rsf/numToSave;
	printf("Average energy = %f\n", m );

}

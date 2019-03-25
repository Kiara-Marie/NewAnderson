#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "metric.h"
#include "aboutRun.h"
#include "utils.h"
using namespace std;
using namespace arma;

AboutRun::AboutRun(int W,int MAXT,int numSites,int iterations,string jMethod){
	this->W = W;
	this->MAXT = MAXT;
	this->numSites = numSites;
	this->iterations = iterations;
	this->jMethod = jMethod;
}

// should be called after construction only
void AboutRun::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){
	if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}
}

void AboutRun::printResult(){

	ostream file(NULL);
	char toAdd[] = "-ABOUT.txt";

	filebuf fileBuffer;
	string fileName = getDate();
	fileName.append(getSeconds());
	fileName.append(toAdd);
	fileBuffer.open(fileName,ios_base::out);
	file.rdbuf(&fileBuffer);

	file<<this->W<<", "<<this->MAXT<<", "<<this->numSites<<", "<<this->iterations<<"\n";
	file<<"W"<<", "<<"MAXT"<<", "<<"numSites"<<", "<<"iterations"<<"\n"<<"\n";
	file<<this->jMethod;
}

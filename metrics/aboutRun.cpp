#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <iomanip>
#include "metric.h"
#include "aboutRun.h"
#include "utils.h"
using namespace std;
using namespace arma;

AboutRun::AboutRun(int W,double MAXT,int numSites,int iterations,string jMethod,string eMethod){
	this->W = W;
	this->MAXT = MAXT;
	this->numSites = numSites;
	this->iterations = iterations;
	this->jMethod = jMethod;
	this->eMethod = eMethod;
	cout << W << MAXT << numSites << iterations << jMethod << eMethod << "\n";
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
	file<<setprecision(3);
	file<<this->eMethod;
	file<<this->W<<", "<<this->MAXT<<", "<<this->numSites<<", "<<this->iterations<<"\n";
	file<<"W"<<", "<<"MAXT"<<", "<<"numSites"<<", "<<"iterations"<<"\n"<<"\n";
	file<<this->jMethod;
}

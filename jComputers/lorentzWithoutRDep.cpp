#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "lorentzWithoutRDep.h"

using namespace std;
using namespace arma;


LorentzWithoutRDep::LorentzWithoutRDep(double arg1,int nnOnly, int arg3) : JComputer(arg1,nnOnly, arg3) {
	// avg distance from one particle to next:
	//		(10^12) particles/cm^3
	// 1/10^12 cm^3 / particle
	// 0.5/10^12 cm avg distance between them
	// so our units will be 1/10^13 cm

	this->t = arg1; // 1/10^13 cm
	this->gamma = arg3;
	this->desc<<"j_ij = lorentzian(e_i-e_j)/r**3, with t = "<<this->t<< " and gamma = "<<this->gamma;
	this->desc<<"\n"<< this->t<< "/ (1 + {(e_i - e_j)/"<<this->gamma<<"}^2) / r_ij**3\n";
	if (this->nnOnly){
		this->desc<<"j_ij on nearest neighbours only\n";
	}
	this->needsEnergy = 1;
	cout<<this->desc.str();
}
double LorentzWithoutRDep::jFinder(int xi,int xj){
	if (this->nnOnly && (xi -xj > 1)){
	return 0;
	}
	double delta = this->info(xi) - this->info(xj);
	double r = 5*(xi - xj);
	double denom = 1 + (delta/this->gamma)*(delta/this->gamma);
	double j = this->t / denom;
	return j;
}

void LorentzWithoutRDep::additionalInfo(vec info){
	this->info = info;
}

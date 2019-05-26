#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "lorentz.h"

using namespace std;
using namespace arma;


Lorentz::Lorentz(int arg1,int nnOnly, int arg3) : JComputer(arg1,nnOnly, arg3) {

	this->t = arg1;
	this->gamma = arg3;
	this->desc<<"j_ij = lorentzian(e_i-e_j)/r**3, with t = "<<this->t<< " and gamma = "<<this->gamma;
	this->desc<<"\n"<< this->t<< "/ (1 + {(e_i - e_j)/"<<this->gamma<<"}^2) / r_ij**3\n";
	this->needsEnergy = 1;
}
double Lorentz::jFinder(int xi,int xj){
	if (this->nnOnly && (xi -xj > 1)){
	return 0;
	}
	double delta = this->info(xi) - this->info(xj);
	double r = xi - xj;
	double denom = 1 + (delta/this->gamma)*(delta/this->gamma);
	double j = this->t / denom;
	j = j/(r*r*r);
	return j;
}

void Lorentz::additionalInfo(vec info){
	this->info = info;
}

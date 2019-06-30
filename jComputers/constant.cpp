#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "constant.h"

using namespace std;
using namespace arma;


Constant::Constant(double arg1,int nnOnly, int arg3) : JComputer(arg1,nnOnly, arg3) {
	this->t = arg1;
	this->rdep = arg3;
	if (this->rdep){
		this->desc<<"j_ij = t/r**3, with t = "<<this->t;
	} else {
		this->desc<<"j_ij = t, with t = "<<this->t;
	}
	if (this->nnOnly){
		this->desc<<"j_ij on nearest neighbours only\n";
	}
	this->needsEnergy = 0;
	cout<<this->desc.str();

}
double Constant::jFinder(int xi,int xj){
	if (this->nnOnly && (xi -xj > 1)){
	return 0;
	}
	double r = (xi - xj);
	double j = this->t;
	if (this->rdep){
		j = j /(r*r*r);
	}
	return j;
}

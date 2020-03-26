#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "gauss.h"

using namespace std;
using namespace arma;


Gauss::Gauss(int arg1,int nnOnly, int arg3) : JComputer(arg1,nnOnly, arg3) {

	this->mean = arg1;
	this->stdDev = arg3;
	this->desc<<"j_ij = rand()/r_ij**3, with rand() chosen from Gaussian random distribution with mean";
	this->desc<<this->mean<<" and std dev "<<this->stdDev<<"\n";
	this->needsEnergy = 0;
}
double Gauss::jFinder(int xi,int xj){
	default_random_engine generator;
	normal_distribution<double> distribution(this->mean,this->stdDev);
	double p = distribution(generator);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (this->nnOnly && (xi -xj > 1)){
		return 0;
	}
	if (j > 0.00001){
		return j;
	}
	return 0;
}

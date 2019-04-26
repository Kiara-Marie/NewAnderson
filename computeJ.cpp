#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <random>
#include "utils.h"
#include "computeJ.h"

using namespace std;
using namespace arma;

int stdDev = 1;
ComputeJ::ComputeJ(int MAXT, Funs fun, int nnOnly){
	this->MAXT = MAXT;
	this->fun = fun;
	this->nnOnly = nnOnly;
}
double ComputeJ::jFinder(int xi,int xj){
	switch(this->fun){
		case uniRandT: return uniRandTFun(xi,xj); break;
		case gaussRandT: return gaussRandTFun(xi,xj); break;
		case indUniRandT: return indUniRandTFun(xi,xj); break;
		case constT: return constTFun(xi,xj); break;
	}
	cerr<<"Things are very weird!!!!\n";
	return 0;
}
string ComputeJ::methodDesc(){
	char jMethod[180];

	switch(this->fun){
		case uniRandT:
		 	sprintf(jMethod,"j_ij = rand()/r_ij**3, with rand() chosen from uniform random distribution between 0 and %d\n",this->MAXT);
			break;
		case gaussRandT:
			sprintf(jMethod,"j_ij = rand()/r_ij**3, with rand() chosen from Gaussian random distribution with mean %d and std dev %d\n",this->MAXT,stdDev);
			break;
		case indUniRandT:
			sprintf(jMethod,"j_ij = rand(), with rand() chosen from uniform random distribution between 0 and %d\n",this->MAXT);
			break;
		case constT:
			sprintf(jMethod,"j_ij = %d\n",this->MAXT);
			break;
	}
	if (this->nnOnly){
		strcat(jMethod,"j_ij on nearest neighbours only\n");
	}
	return jMethod;
}

double ComputeJ::uniRandTFun(int xi, int xj){
	double p = rand() % (MAXT + 1);
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
double ComputeJ::gaussRandTFun(int xi, int xj){
	default_random_engine generator;
	normal_distribution<double> distribution(MAXT,stdDev);
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

double ComputeJ::indUniRandTFun(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double j = p;
	if (this->nnOnly && (xi -xj > 1)){
		return 0;
	}
	return j;
}

double ComputeJ::constTFun(int xi, int xj){
	return MAXT;
}

#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"
#include "computeJ.h"

using namespace std;
using namespace arma;

ComputeJ::ComputeJ(int MAXT, Funs fun){
	this->MAXT = MAXT;
	this->fun = fun;
}
double ComputeJ::jFinder(int xi,int xj){
	switch(this->fun){
		case nnUniRandT: return nnUniRandTFun(xi,xj); break;
		case uniformRandT: return uniformRandTFun(xi,xj); break;
	}
	cerr<<"Things are very weird!!!!\n";
	return 0;
}
string ComputeJ::methodDesc(){
	char jMethod[100];

	switch(this->fun){
		case nnUniRandT:
			sprintf(jMethod,"j_ij = rand()/r_ij**3, only on nearest neighbours. \n rand() chosen from uniform random distribution between 0 and %d",this->MAXT);
			break;
		case uniformRandT:
		 	sprintf(jMethod,"j_ij = rand()/r_ij**3, with rand() chosen from uniform random distribution between 0 and %d",this->MAXT);
			break;
	}
	return jMethod;
}
double ComputeJ::uniformRandTFun(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (j > 0.00001){
		return j;
	}
	return 0;
}
double ComputeJ::nnUniRandTFun(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (xi -xj > 1){
		return 0;
	}
	if (j > 0.00001){
		return j;
	}
	return 0;
}

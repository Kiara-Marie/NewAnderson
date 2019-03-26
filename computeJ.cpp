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

ComputeJ::ComputeJ(int MAXT, Funs fun, int nnOnly){
	this->MAXT = MAXT;
	this->fun = fun;
	this->nnOnly = nnOnly;
}
double ComputeJ::jFinder(int xi,int xj){
	switch(this->fun){
		case uniRandT: return uniRandTFun(xi,xj); break;
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

#ifndef _COMPUTEJ_H_
#define _COMPUTEJ_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"

using namespace std;
using namespace arma;

class ComputeJ {
	public:
		enum Funs{uniformRandT,nnUniRandT};
		ComputeJ(int MAXT,Funs fun);
		double jFinder(int xi,int xj);
		string methodDesc();
	private:
		Funs fun;
		int MAXT;
		double uniformRandTFun(int xi, int xj);
		double nnUniRandTFun(int xi, int xj);
};

#endif

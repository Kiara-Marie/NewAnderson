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
		enum Funs{uniRandT,gaussRandT,indUniRandT};
		ComputeJ(int MAXT,Funs fun,int nnOnly);
		double jFinder(int xi,int xj);
		string methodDesc();
	private:
		Funs fun;
		int MAXT;
		int nnOnly;
		double uniRandTFun(int xi, int xj);
		double gaussRandTFun(int xi, int xj);
		double indUniRandTFun(int xi, int xj);
};

#endif

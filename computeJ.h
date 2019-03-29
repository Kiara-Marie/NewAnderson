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
		// TODO write better way of computing J
		enum Funs{uniRandT,gaussRandT};
		ComputeJ(int MAXT,Funs fun,int nnOnly);
		double jFinder(int xi,int xj);
		string methodDesc();
	private:
		Funs fun;
		int MAXT;
		int nnOnly;
		double uniRandTFun(int xi, int xj);
};

#endif

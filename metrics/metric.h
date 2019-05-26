#ifndef _METRIC_H_
#define _METRIC_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

class metric {
	public:
		virtual void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations)=0;
		virtual void printResult()=0;
};

#endif

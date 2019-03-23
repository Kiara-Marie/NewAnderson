#ifndef _AVGEIGVEC_H_
#define _AVGEIGVEC_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

class AvgEigVec : public metric {
	private:
		int iterations = 0;
		mat avgMat;
	public:
		void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations);
		void printResult();
};

#endif

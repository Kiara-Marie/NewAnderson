#ifndef _INVERSEPR_H_
#define _INVERSEPR_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

class InversePR : public metric {
	private:
		vector<double> iprs;
		int iterations;
	public:
		void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations);

		void printResult();
};

#endif

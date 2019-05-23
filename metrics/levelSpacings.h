#ifndef _LEVELSPACINGS_H_
#define _LEVELSPACINGS_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"

using namespace std;
using namespace arma;

class LevelSpacings : public metric {
	private:
		vector<double> spacings;
		vec avgENPrime;
		int iterations = 0;
		void printS();
		void printENPrime();
	public:
		void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations);
		void printResult();
};

#endif

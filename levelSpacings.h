#ifndef _LEVELSPACINGS_H_
#define _LEVELSPACINGS_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

class LevelSpacings : public metric {
	private:
		vector<double> spacings;
	public:
		void save(const vec &eigval,const mat &eigvec,const mat &A);

		void printResult();
};

#endif

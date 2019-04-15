#ifndef _ENERGYLEVELS_H_
#define _ENERGYLEVELS_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"

using namespace std;
using namespace arma;

class EnergyLevels : public metric {
	private:
		vector<double> energies;
		int iterations = 0;
	public:
		void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations);
		void printResult();
};

#endif

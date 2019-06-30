#ifndef _GAUSS_H_
#define _GAUSS_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "../jComputer.h"

using namespace std;
using namespace arma;

class Gauss : public JComputer {
	private:
		double mean;
		double stdDev;

	public:
		Gauss(int arg1,int nnOnly, int arg3);
		double jFinder(int xi,int xj);
};

#endif

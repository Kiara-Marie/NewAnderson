#ifndef _CONSTANT_H_
#define _CONSTANT_H_
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

class Constant : public JComputer {
	private:
		double t;
		int rdep;

	public:
		Constant(double arg1,int nnOnly, int arg3);
		double jFinder(int xi,int xj);
};

#endif

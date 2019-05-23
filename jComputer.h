#ifndef _JCOMPUTER_H_
#define _JCOMPUTER_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"

using namespace std;
using namespace arma;

class JComputer {
	public:
		JComputer(int arg1,int nnOnly, int arg3);
		double jFinder(int xi,int xj);
		string methodDesc();
};

#endif

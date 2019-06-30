#ifndef _JCOMPUTERFACTORY_H_
#define _JCOMPUTERFACTORY_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"

using namespace std;
using namespace arma;

class JComputerFactory {
	public:
		enum Funs{uniRandT,gaussRandT,indUniRandT,constT,lorentzT};
		JComputer computeJ(Funs fun, int arg1,int nnOnly, int arg3);
};

#endif

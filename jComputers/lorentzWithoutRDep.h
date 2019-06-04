#ifndef _LORENTZWITHOUTRDEP_H_
#define _LORENTZWITHOUTRDEP_H_
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

class LorentzWithoutRDep : public JComputer {
	private:
		vec info;
		double t;
		double gamma;

	public:
		LorentzWithoutRDep(double arg1,int nnOnly, int arg3);
		double jFinder(int xi,int xj);
		void additionalInfo(vec info);

};

#endif

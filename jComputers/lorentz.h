#ifndef _LORENTZ_H_
#define _LORENTZ_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"
#include "JComputer.h"

using namespace std;
using namespace arma;

class Lorentz : public JComputer {
	private:
		vec info;
		double t;
		double gamma;

	public:
		Lorentz(int arg1,int nnOnly, int arg3);
		double jFinder(int xi,int xj);
		string methodDesc();
		void additionalInfo(vec info);

};

#endif

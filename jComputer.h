#ifndef _JCOMPUTER_H_
#define _JCOMPUTER_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>

using namespace std;
using namespace arma;

class JComputer {
	public:
		int needsEnergy = 0;
		explicit JComputer(double arg1,int nnOnly, int arg3);
		~JComputer();
		JComputer( const JComputer& anotherJComputer );
		virtual double jFinder(int xi,int xj);
		virtual string methodDesc();
		virtual void additionalInfo(vec info);
	protected:
		int nnOnly;
		stringstream desc;

};

#endif

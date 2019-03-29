#ifndef _ABOUTRUN_H_
#define _ABOUTRUN_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"

using namespace std;
using namespace arma;

class AboutRun : public metric {
	private:
		// onsite disorder
		int W;
		int MAXT;
		int numSites;
		int iterations;
		string jMethod;
	public:
		AboutRun(int W,int MAXT,int numSites,int iterations,string jMethod);
		void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations);
		void printResult();

};

#endif

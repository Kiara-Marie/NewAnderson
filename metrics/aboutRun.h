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
		int W;
		double MAXT;
		int numSites;
		int iterations;
		string jMethod;
		string eMethod;
	public:
		AboutRun(int W,double MAXT,int numSites,int iterations,string jMethod, string eMethod);
		void save(const vec &eigval,const mat &eigvec,const mat &A, int iterations);
		void printResult();

};

#endif

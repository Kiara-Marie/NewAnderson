#ifndef _RESULTFINDER_H_
#define _RESULTFINDER_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"

class ResultFinder{

	private:
		vector<metric*> metrics;
	public:
		ResultFinder(vector<metric*> metrics);
		void saveResults(mat& A);
		void printResults();
};

#endif

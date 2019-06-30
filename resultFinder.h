#ifndef _RESULTFINDER_H_
#define _RESULTFINDER_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metrics/metric.h"

class ResultFinder{

	protected:
		vector<metric*> metrics;
	public:
		explicit ResultFinder(vector<metric*> metrics);
		void saveResults(mat& A, int iterations);
		virtual void printResults();
};

#endif

#ifndef _RESULTNODIAG_H_
#define _RESULTNODIAGH_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metrics/metric.h"

class ResultNoDiag: public ResultFinder{

	private:
		vector<metric*> metrics;
	public:
		ResultNoDiag(vector<metric*> metrics);
		void saveResults(mat& A, int iterations);
};

#endif

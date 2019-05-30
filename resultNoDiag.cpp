#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metrics/metric.h"
#include "resultFinder.h"
#include "resultNoDiag.h"
using namespace std;
using namespace arma;

ResultNoDiag::ResultNoDiag(vector<metric*> metrics): ResultFinder(metrics){
	this->metrics = metrics;
}

void ResultNoDiag::saveResults(mat& A, int iterations){
	vec eigval = sort(A.diag());
	//eigval.print("eigvals: are they sorted?\n");
	mat eigvec = A;
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->save(eigval, eigvec, A, iterations);
	}
}

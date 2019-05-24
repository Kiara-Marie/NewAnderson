#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "levelSpacings.h"
using namespace std;
using namespace arma;


JComputer::JComputer(int arg1,int nnOnly, int arg3){
	this->nnOnly = nnOnly;
}


void JComputer::additionalInfo(vec info){
}

double JComputer::JFinder(int xi, int xj){
	if (this->nnOnly && (xi -xj > 1)){
	return 0;
	}
}

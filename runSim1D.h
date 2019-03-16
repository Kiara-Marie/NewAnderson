#ifndef _RUNSIM1D_H_
#define _RUNSIM1D_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

void runSim1D(double W, int length, mat& A);

double findT(int xi, int xj);
int is_symmetric(const mat& A);

#endif

#ifndef _RUNSIM1D_H_
#define _RUNSIM1D_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "computeJ.h"

using namespace std;
using namespace arma;

void runSim1D(double W, int length, mat& A, ComputeJ jComputer);

double findT(int xi, int xj);
// function to ensure Hermitian matrices are being produced
int is_symmetric(const mat& A);

#endif

#ifndef _RUNSIMSIMPLE_H_
#define _RUNSIMSIMPLE_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
#include "runSim1D.h"

using namespace std;
using namespace arma;

void runSimSimple(double W, int length, mat& A, JComputer& jComputer);

double findT(int xi, int xj);

#endif

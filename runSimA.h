#ifndef _RUNSIMA_H_
#define _RUNSIMA_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
#include "runSim1D.h"

using namespace std;
using namespace arma;

void runSimA(double W, int length, mat& A, JComputer& jComputer);
void getEnergiesA(int length, vec& energies, double W);
#endif

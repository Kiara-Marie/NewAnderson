#ifndef _RUNSIMA_H_
#define _RUNSIMA_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"

using namespace std;
using namespace arma;

void runSimA(double W, int length, mat& A, JComputer& jComputer);

double findT(int xi, int xj);
int is_symmetric(const mat& A);
double energyLambda(double n);
void getEnergies(int length, vec& energies, double W);
#endif

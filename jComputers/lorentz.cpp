#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "utils.h"
#include "lorentz.h"

using namespace std;
using namespace arma;


Lorentz::Lorentz(int arg1,int nnOnly, int arg3){
	this->super(arg1, nnOnly, arg3);
	this->t = arg1;
	this->gamma = arg3;

}
double Lorentz::jFinder(int xi,int xj){
	this->super();
	double delta = this->info(xi) - this->info(xj);
	double r = xi - xj;
	double denom = 1 + (delta/stdDev)*(delta/stdDev);
	double j = MAXT / denom;
	j = j/(r*r*r);
	return j;
}
string methodDesc();
void additionalInfo(vec info);



#endif

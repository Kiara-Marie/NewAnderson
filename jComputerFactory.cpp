#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <fstream>
#include <ostream>
#include "jComputerFactory.h"
#include "jComputer.h"
#include "jComputers/lorentz.h"

using namespace std;
using namespace arma;

JComputer JComputerFactory::computeJ(Funs fun, int arg1,int nnOnly, int arg3){
	switch(fun){
		//case uniRandT: return uniRandT(arg1, nnOnly, arg3); break;
		//case gaussRandT: return gaussRandT(arg1, nnOnly, arg3); break;
		//case indUniRandT: return indUniRand(arg1, nnOnly, arg3); break;
		//case constT: return constT(arg1, nnOnly, arg3); break;
		case lorentzT: return Lorentz(arg1, nnOnly, arg3); break;
	}
	cerr<<"Things are very weird!!!!\n";
	return Lorentz(arg1, nnOnly, arg3);
}

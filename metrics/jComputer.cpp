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


string JComputer::methodDesc(){
	char jMethod[180];
	sprintf(jMethod,this->desc);
	if (this->nnOnly){
		strcat(jMethod,"j_ij on nearest neighbours only\n");
	}
	return jMethod;
}

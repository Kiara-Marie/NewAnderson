#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
using namespace std;
using namespace arma;


JComputer::JComputer(double arg1,int nnOnly, int arg3){
	this->nnOnly = nnOnly;
}

JComputer::~JComputer(){
}

JComputer::JComputer( const JComputer& anotherJComputer ){
	this->nnOnly = anotherJComputer.nnOnly;
	this->desc<<anotherJComputer.desc.str();
}

double JComputer::jFinder(int xi, int xj){
	cerr<<"someone is trying to use a plain jcomputer!\n";
	throw "Trying to use abstract j computer!\n";
}

string JComputer::methodDesc(){
	return this->desc.str();
}

void JComputer::additionalInfo(vec info){
}

#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
using namespace std;
using namespace arma;


JComputer::JComputer(int arg1,int nnOnly, int arg3){
	this->nnOnly = nnOnly;
}

JComputer::~JComputer(){
	delete &this->desc;
}

JComputer::JComputer( const JComputer& anotherJComputer ){
	this->nnOnly = anotherJComputer.nnOnly;
	this->desc<<anotherJComputer.desc.str();
}

double JComputer::jFinder(int xi, int xj){
	cerr<<"someone is trying to use a plain jcomputer\n";
	return 0;
}

string JComputer::methodDesc(){
	char jMethod[180];
	sprintf(jMethod,"%s",this->desc.str());
	if (this->nnOnly){
		strcat(jMethod,"j_ij on nearest neighbours only\n");
	}
	return jMethod;
}

void JComputer::additionalInfo(vec info){
}

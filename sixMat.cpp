#include "sixMat.h"

SixMat::SixMat(int length){
	this->length = length;
	this->bigMat.zeros(pow(length,3), pow(length,3));
	this->numRows = pow(length,3);
}

void SixMat::set(int xi, int yi, int zi, int xj, int yj, int zj, double to){
	int i = xi*this->length*this->length + yi*this->length + zi;
	int j = xj*this->length*this->length + yj*this->length + zj;
	bigMat(i,j) = to;
}

void SixMat::diag(const vec& energies){
	this->bigMat.diag() = energies;
}

void SixMat::print(string s){
	this->bigMat.print(s);
}

vec SixMat::eigs(){
	vec ret(pow(length,3));
	mat test(this->numRows, this->numRows);
	test.zeros();
	vec energies = randu<vec>(this->numRows);
	energies = energies * 5;
	test.diag() = energies;
	vec tVec = eig_sym(test);
	//ret.subvec(0,this->numRows-2) = eig_sym(test,this->numRows-1);
	//ret(this->numRows-1) = eig_sym(test,1,"sm");
	//ret.subvec(0,pow(length,3)-2)= eig_sym(this->bigMat,pow(length,3)-1);
	//ret(pow(length,3)-1) = eig_sym(this->bigMat,1,"sm");
	return ret;
}

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

void SixMat::print(ostream& arrayFile){
	this->bigMat.print(arrayFile);
}

vec SixMat::eigs(){
	vec ret(this->numRows);
	vec eigval = eigs_sym(this->bigMat, this->numRows-1);
	vec smallestEigVal = eigs_sym(this->bigMat, 1,"sm");
	ret.subvec(1,this->numRows-1) = eigval;
	ret.subvec(0,0) = smallestEigVal;
	return ret;
}

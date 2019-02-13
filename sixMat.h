#ifndef _SIXMAT_H_
#define _SIXMAT_H_
#include <iostream>
#include <cmath>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;


class SixMat{
	public:
		SixMat(int length);
		void set(int xi, int xy, int xz, int xj, int yj, int zj, double to);
		void diag(const vec& energies);
		void print(string s);
		vec eigs();

	private:
		SpMat<double> bigMat;
		int length;
		int numRows;
};

#endif
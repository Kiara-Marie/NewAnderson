#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metric.h"
#include "levelSpacings.h"
using namespace std;
using namespace arma;

void LevelSpacings::save(const vec &eigval,const mat &eigvec,const mat &A, int iterations){
	if (this->avgENPrime.n_elem == 0){
		this->avgENPrime = zeros(eigval.n_elem);
	} else if (this->avgENPrime.n_elem != eigval.n_elem){
		cerr<<"Inconsistent number of eigenvalues!\n";
	}

	if (this-> iterations == 0){
		this->iterations = iterations;
	} else if (this-> iterations != iterations){
		cerr<<"Inconsistent number of iterations!\n";
	}

	double up;
	double down;

	for(int i = 1; i<eigval.n_elem-2; i++){
		up = eigval(i+1) - eigval(i);
		down = eigval(i) - eigval(i - 1);
		this->spacings.push_back(up);
		if (up > 3e-15){
		//	cout<<"i = "<<i<<", Spacing = "<<up<<"\n";
		}
		this->avgENPrime(i) += up/down;
	}
	return;
}

void LevelSpacings::printResult(){
	//ostream spacingsFile;
	//spacingsFile.rdbuf(cout.rdbuf());
	cout<<"All Spacings:\n";
	for (int i = 1; i< spacings.size(); i++){
			cout<<spacings[i]<< ", ";
	}

	//ostream ENFile = getENFile();
	this->avgENPrime = this->avgENPrime / iterations;
cout<<"Average En' between levels: \n";
	avgENPrime.print();

	return;
}

/*ostream getSFile(){
	string date = getDate();
	fopen("")
}
*/

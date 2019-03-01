#include <iostream>
#include <armadillo>
#include <math.h>
#include <string>
#include <fstream>
#include <ostream>
#include "sixMat.h"

using namespace std;
using namespace arma;

int main(int argc, char** argv){


	// set variables
	double W = 5;
	int length = 3;
	double t = 1;
	int noWrite = 0;
	ostream arrayFile(NULL);
	ostream eigValsFile(NULL);
	filebuf arrayBuffer;
	filebuf eigBuffer;

	if (argc > 1){
		W = stoi(argv[1]);
	}
	if (argc > 2){
		length = stoi(argv[2]);
	}
	if (argc > 3){
		try{
			string argv3 = (string) argv[3];
			if (argv3 == "nw"){
				noWrite = 1;
			} else{
			arrayBuffer.open(argv[3],ios_base::out);
			arrayFile.rdbuf(&arrayBuffer);
			}
		}
		catch(...){
			cout<<"Array File name invalid, printing to stdout\n";
			arrayFile.rdbuf(cout.rdbuf());
		}
	} else {
		arrayFile.rdbuf(cout.rdbuf());
	}
	if (argc > 4){
		try{
			eigBuffer.open(argv[4],ios_base::out);
			eigValsFile.rdbuf(&eigBuffer);
		} catch(...) {
			cout<<"Eigval File name invalid, printing to stdout\n";
			eigValsFile.rdbuf(cout.rdbuf());
		}
	}
	 else {
		eigValsFile.rdbuf(cout.rdbuf());
	}

	SixMat A = runSim(W, length, t);
	
	if (!noWrite){
		A.print(arrayFile);
		cout<<"No write was false\n";
	}
	vec eigval = A.eigs();
	eigval.print(eigValsFile);

	return 0;
}

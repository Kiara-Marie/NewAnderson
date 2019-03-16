#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;
int is_symmetric(mat& A);
int main(int argc, char** argv){
	mat A = randu<mat>(5,5);
	cout<<"A: \n";
	A.print();
	cout<<"A is symmetric? "<<is_symmetric(A)<<"\n";
	vec eigval;
	mat eigvec;
	eig_sym( eigval, eigvec, A );
	cout<<"Eigenvalues: \n";
	eigval.print();
	cout<<"Eigenvectors: \n";
	eigvec.print();

	vec firstVec = eigvec.col(0);
	double firstVal = eigval(0);
	firstVec = firstVec * firstVal;
	cout<<"First eigenvec multiplied by first eigenval\n";
	firstVec.print();
	cout<<"And divided\n";
	firstVec = firstVec / firstVal;
	firstVec.print();
	return 0;
}

int is_symmetric(mat& A){
	if (A.n_rows != A.n_cols){
		return 0;
	}
	for (int i = 0; i< A.n_rows;i++){
		for (int j = 0; j<A.n_cols;j++){
			if(A(i,j) != A(j,i)){
				return 0;
			}
		}
	}
	return 1;
}

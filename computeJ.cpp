double ComputeJ::uniformRandT(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (j > 0.00001){
		return j;
	} else return 0;
}
double ComputeJ::nnUniRandT(int xi, int xj){
	double p = rand() % (MAXT + 1);
	double r = xi - xj;
	double j = p/(r*r*r);
	if (xi -xj > 1){
		return 0;
	}
	if (j > 0.00001){
		return p;
	} else return 0;

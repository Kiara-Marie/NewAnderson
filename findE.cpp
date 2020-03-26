// Quantum defect as determined by M. Bixon and J. Jortner,
// J. Chem. Phys. 105, 1363 ~1996.
double QD0 = 1.21;
double QD1 = 0.7286;
double QD2 = -0.05;

// g as determined by  Murgu, E.; Martin, J. D. D.; Gallagher, T. F..
// The Journal of Chemical Physics 2001,115(15),7032–7040.
double QD3 = 0.0101;
double QDE = 0;
// find quantum defect of given l
double delta(char l){
    switch (l){
        case 0:
            return QD0;
            break;
        case 1:
            return QD1;
            break;
        case 2:
            return QD2;
            break;
        case 3:
            return QD3;
        default:
            return QDE;
          }
}
// find binding energy of given state (in terms of R*Z m^-1)
double bindingEnergy(char pqn, char l){
    return (1/((pqn - delta(l))*(pqn - delta(l))));
}

#!/bin/bash -l
#SBATCH --job-name=bigBoy
#SBATCH --account=def-edgrant
#SBATCH --time=24:00:00
#SBATCH --mem=1000000

module load armadillo
./main 3 30 nw bigEigVals.txt

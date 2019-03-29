#!/bin/bash -l
#SBATCH --job-name=arrayOfWs
#SBATCH --account=def-edgrant
#SBATCH --time=23:00:00
#SBATCH --mem=100000
#SBATCH --array=0-7

module load armadillo
./epsilonSum1D $SLURM_ARRAY_TASK_ID 1000 25

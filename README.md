This program creates a matrix representing a lattice of two-level systems with numSites sites, with random spacings between the levels, as specified in the diagonal terms, with random interactions on the off-diagonals.  


Some files in this repository are not used in the current version of the program.
Those used in the current version are:

epsilonSum1D.cpp - This is essentially the main file, which can be compiled and run from the command line.

metric.cpp (metric.h) - This is an abstract class to describe different metrics which might be used to analyse the results of this computation. Subclasses currently include:

	levelSpacings.cpp (levelSpacings.h)
	avgEigVec.cpp (avgEigVec.h)
	aboutRun.cpp (aboutRun.h)

utils.cpp (utils.h) - This is a file to put miscellaneous useful functions, which currently just contains functions to create date strings

runSim1D.cpp(runSim1D.h) - This is the file which actually generates the random matrices

resultFinder.cpp (resultFinder.h) - This file diagonalizes the matrices and calls the functions in the metrics to find infromation about them

Makefile - This compiles the whole thing

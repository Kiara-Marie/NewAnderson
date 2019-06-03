CXX = g++
CXXFLAGS = -Wall -g  -O2 -larmadillo -std=c++14
objects = metrics/avgEigVec.o metrics/inversePR.o metrics/levelSpacings.o  metrics/metric.o jComputer.o resultFinder.o \
		    jComputers/lorentz.o runSim1D.o metrics/utils.o metrics/aboutRun.o metrics/energyLevels.o \
			findE.o runSimA.o runSimSimple.o resultNoDiag.o
epsilonSum1D: $(objects)
	$(CXX) epsilonSum1D.cpp $(CXXFLAGS) -o epsilonSum1D $(objects)
clean:
	rm epsilonSum1D $(objects)

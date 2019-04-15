CXX = g++
CXXFLAGS = -Wall -g  -O2 -larmadillo -std=c++14
objects = avgEigVec.o inversePR.o levelSpacings.o  metric.o resultFinder.o \
			runSim1D.o utils.o aboutRun.o computeJ.o energyLevels.o
epsilonSum1D: $(objects)
	$(CXX) epsilonSum1D.cpp $(CXXFLAGS) -o epsilonSum1D $(objects)
clean:
	rm epsilonSum1D $(objects)

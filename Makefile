main: main.cpp sixMat.o sixMat.h runSim.o runSim.h
	g++ main.cpp sixMat.o runSim.o -o main -O2 -larmadillo -std=c++14
epsilonSum1D: epsilonSum1D.cpp runSim1D.o runSim1D.h resultFinder.h resultFinder.o levelSpacings.o levelSpacings.h metric.h metric.o
	g++ epsilonSum1D.cpp runSim1D.o resultFinder.o levelSpacings.o metric.o -o epsilonSum1D -O2 -larmadillo -std=c++14
runSim1D.o: runSim1D.cpp runSim1D.h
	g++ -c runSim1D.cpp -O2 -larmadillo -std=c++14
sixMat.o: sixMat.cpp sixMat.h
	g++ -c sixMat.cpp -O2 -larmadillo -std=c++14
runSim.o: runSim.cpp runSim.h
	g++ -c runSim.cpp -O2 -larmadillo -std=c++14
resultFinder.o: resultFinder.cpp resultFinder.h metric.o metric.h
	g++ -c resultFinder.cpp metric.o metric.h -O2 -larmadillo -std=c++14
levelSpacings.o: levelSpacings.cpp levelSpacings.h metric.o metric.h
	g++ -c levelSpacings.cpp metric.o metric.h -O2 -larmadillo -std=c++14
metric.o: metric.cpp metric.h
	g++ -c metric.cpp metric.h -O2 -larmadillo -std=c++14
clean:
	rm main

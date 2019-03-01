main: main.cpp sixMat.o sixMat.h runSim.o runSim.h
	g++ main.cpp sixMat.o runSim.o -o main -O2 -larmadillo -std=c++14
sixMat.o: sixMat.cpp sixMat.h
	g++ -c sixMat.cpp -O2 -larmadillo -std=c++14
runSim.o: runSim.cpp runSim.h
	g++ -c runSim.cpp -O2 -larmadillo -std=c++14
clean:
	rm main

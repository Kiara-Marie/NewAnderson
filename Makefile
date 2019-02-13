main: main.cpp sixMat.o sixMat.h
	g++ main.cpp -o main -O2 -larmadillo -std=c++14
sixMat.o: sixMat.cpp sixMat.h
	g++ -c sixMat.cpp -O2 -larmadillo -std=c++14
clean:
	rm main

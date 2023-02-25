randmst: mst.o
	g++ -std=c++0x -Wall mst.o -o randmst

mst.o: mst.cpp
	g++ -c mst.cpp

clean:
	rm *.o randmst

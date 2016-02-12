all: verify

verify: Calculator.o CoveringArray.o main.o OccurenceArrayKey.o OccurenceLocationArray.o OccurenceArray.o Column.o
	g++ -fopenmp -o parallel_verify Calculator.o CoveringArray.o main.o OccurenceArrayKey.o OccurenceLocationArray.o OccurenceArray.o Column.o

main.o: main.cpp CoveringArray.h
	g++ -c -fopenmp -std=c++11 main.cpp

CoveringArray.o: OccurenceArray.h OccurenceLocationArray.h Column.h CoveringArray.cpp
	g++ -c -fopenmp -std=c++11 CoveringArray.cpp

OccurenceArray.o: Column.h OccurenceArray.cpp OccurenceArrayKey.h Calculator.h
	g++ -c -fopenmp -std=c++11 OccurenceArray.cpp

OccurenceLocationArray.o: OccurenceLocationArray.cpp OccurenceArray.h
	g++ -c -fopenmp -std=c++11 OccurenceLocationArray.cpp

OccurenceArrayKey.o: Column.h OccurenceArrayKey.cpp
	g++ -c -fopenmp -std=c++11 OccurenceArrayKey.cpp

Calculator.o: Calculator.cpp
	g++ -c -fopenmp -std=c++11 Calculator.cpp

clean:
	rm *.o

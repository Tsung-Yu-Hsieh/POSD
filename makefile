all: hw2

hw2: mainTerm.o Atom.o Number.o Variable.o
	g++ -o hw2 mainTerm.o Atom.o Number.o Variable.o -lgtest -lpthread
mainTerm.o: mainTerm.cpp utTerm.h
	g++ -std=c++11 -c mainTerm.cpp
Atom.o: atom.h Atom.cpp
	g++ -std=c++11 -c Atom.cpp
Number.o: number.h Number.cpp
	g++ -std=c++11 -c Number.cpp
Variable.o: variable.h Variable.cpp
	g++ -std=c++11 -c Variable.cpp

clean:
		rm -f *.o hw2
stat:
		wc *.h *.cpp

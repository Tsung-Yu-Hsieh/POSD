all: hw4

hw4: mainVariable.o Number.o Atom.o Variable.o  List.o

ifeq (${OS}, Windows_NT)
	g++ -o hw4  mainVariable.o Atom.o Number.o Variable.o  List.o -lgtest
else
	g++ -o hw4  mainVariable.o Atom.o Number.o Variable.o  List.o -lgtest -lpthread
endif

mainVariable.o: mainVariable.cpp utVariable.h utAtom.h utList.h utStruct.h
		g++ -std=gnu++0x -c mainVariable.cpp

Number.o: number.h Number.cpp
		g++ -std=gnu++0x -c Number.cpp

Atom.o: atom.h Atom.cpp
	g++ -std=gnu++0x -c Atom.cpp

Variable.o: variable.h Variable.cpp
	g++ -std=gnu++0x -c Variable.cpp

List.o: list.h List.cpp
	g++ -std=gnu++0x -c List.cpp
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif

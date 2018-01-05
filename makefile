all: hw8 shell


hw8: mainScanner.o Number.o Atom.o Variable.o List.o Struct.o

ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainScanner.o Atom.o Number.o Variable.o List.o Struct.o -lgtest
else
	g++ -o hw8 mainScanner.o Atom.o Number.o Variable.o List.o Struct.o -lgtest -lpthread
endif

shell: shell.o Atom.o List.o Struct.o Variable.o scanner.h parser.h
ifeq (${OS}, Windows_NT)
		g++ -o shell shell.o Atom.o Variable.o List.o Struct.o -lgtest
else
		g++ -o shell shell.o Atom.o Variable.o List.o Struct.o -lgtest -lpthread
endif


shell.o: shell.cpp scanner.h atom.h struct.h variable.h parser.h exp.h
	g++ -std=gnu++0x -c shell.cpp

mainScanner.o: mainScanner.cpp scanner.h parser.h iterator.h exception.h expression.h
		g++ -std=gnu++0x -c mainScanner.cpp

Number.o: number.h Number.cpp
		g++ -std=gnu++0x -c Number.cpp

Atom.o: atom.h Atom.cpp
	g++ -std=gnu++0x -c Atom.cpp

Variable.o: variable.h Variable.cpp
	g++ -std=gnu++0x -c Variable.cpp

Struct.o: Struct.cpp struct.h
	g++ -std=gnu++0x -c Struct.cpp

List.o: list.h List.cpp
	g++ -std=gnu++0x -c List.cpp

Node.o: node.h Node.cpp
		g++ -std=gnu++0x -c Node.cpp


clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw8 shell
endif

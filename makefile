all: hw8 shell

hw8: mainScanner.o Atom.o List.o Struct.o

ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainScanner.o Atom.o List.o Struct.o  -lgtest
else
	g++ -o hw8 mainScanner.o Atom.o List.o Struct.o -lgtest -lpthread
endif

shell: shell.o Atom.o List.o Struct.o scanner.h parser.h
ifeq (${OS}, Windows_NT)
		g++ -o shell shell.o Atom.o List.o Struct.o -lgtest
else
		g++ -o shell shell.o Atom.o List.o Struct.o -lgtest -lpthread
endif

shell.o: shell.cpp scanner.h  atom.h struct.h variable.h parser.h exp.h
	g++ -std=gnu++0x -c shell.cpp

Atom.o: Atom.cpp atom.h variable.h
	g++ -std=c++11 -c Atom.cpp

List.o:List.cpp list.h
	g++ -std=c++11 -c List.cpp

Struct.o:Struct.cpp struct.h
	g++ -std=c++11 -c Struct.cpp

mainScanner.o: mainScanner.cpp scanner.h atom.h struct.h variable.h parser.h exception.h expression.h
	g++ -std=c++11 -c mainScanner.cpp

clean:
	rm -f *.o shell hw8
stat:
	wc *.h *.cpp

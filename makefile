all: hw5

hw5: mainScanner.o Number.o Atom.o Variable.o List.o

ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainScanner.o Atom.o Number.o Variable.o List.o -lgtest
else
	g++ -o hw5 mainScanner.o Atom.o Number.o Variable.o List.o -lgtest -lpthread
endif

mainScanner.o: mainScanner.cpp utScanner.h utParser.h scanner.h parser.h struct.h
				g++ -std=gnu++0x -c mainScanner.cpp

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
	rm -f *.o hw5
endif

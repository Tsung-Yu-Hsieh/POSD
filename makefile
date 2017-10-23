all: madRace utVariable utScanner utStruct

madRace: mainMadRace.o
	g++ -o madRace mainMadRace.o -lgtest -lpthread
mainMadRace.o: mainMadRace.cpp madRace.h utMadRace.h
	g++ -std=c++11 -c mainMadRace.cpp

utStruct: mainAtom.o Atom.o Number.o Variable.o List.o
		g++ -o utStruct mainAtom.o Atom.o Number.o Variable.o List.o -lgtest -lpthread
mainAtom.o: mainAtom.cpp utAtom.h atom.h utStruct.h struct.h utList.h
			g++ -std=c++11 -c mainAtom.cpp

utVariable: mainVariable.o Atom.o Number.o Variable.o
							g++ -o utVariable mainVariable.o Atom.o Number.o Variable.o -lgtest -lpthread
mainVariable.o: mainVariable.cpp utVariable.h variable.h
							g++ -std=c++11 -c mainVariable.cpp


Atom.o: Atom.cpp atom.h
	g++ -std=c++11 -c Atom.cpp

Number.o: number.h Number.cpp
	g++ -std=c++11 -c Number.cpp

Variable.o: variable.h Variable.cpp
	g++ -std=c++11 -c Variable.cpp
List.o: list.h List.cpp
		g++ -std=c++11 -c List.cpp
#exp: mainExp.o
#	g++ -o exp mainExp.o -lgtest -lpthread
#mainExp.o: mainExp.cpp exp.h global.h
#	g++ -std=c++11 -c mainExp.cpp

utScanner: mainScanner.o scanner.h utScanner.h
	g++ -o utScanner mainScanner.o -lgtest -lpthread
mainScanner.o: mainScanner.cpp utScanner.h scanner.h  atom.h struct.h variable.h
		g++ -std=c++11 -c mainScanner.cpp

#utTerm: mainTerm.o term.o struct.o var.o list.o
#	g++ -o utTerm mainTerm.o term.o var.o struct.o list.o -lgtest -lpthread
#mainTerm.o: mainTerm.cpp utTerm.h term.h var.h utStruct.h struct.h list.h utList.h
#	g++ -std=c++11 -c mainTerm.cpp
#term.o: term.h term.cpp
#	g++ -std=c++11 -c term.cpp
#struct.o: struct.h struct.cpp
#	g++ -std=c++11 -c struct.cpp
#var.o: var.h var.cpp
#g++ -std=c++11 -c var.cpp
#list.o: list.h list.cpp term.h var.h
#	g++ -std=c++11 -c list.cpp
clean:
	rm -f *.o madRace utStruct utVariable utScanner
stat:
	wc *.h *.cpp

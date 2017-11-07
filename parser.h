#ifndef PARSER_H
#define PARSER_H
#include "scanner.h"
#include "term.h"
#include "number.h"
#include "variable.h"
#include "atom.h"
#include "struct.h"
#include "list.h"

#include <vector>
using std::vector;
class Parser{
  public:
    Parser(Scanner scanner):_scanner(scanner){}
    Term* createTerm(){

      int token = _scanner.nextToken();

      if(token == VAR) {
        return new Variable(symtable[_scanner.tokenValue()].first);
      } else if(token == NUMBER) {
        return new Number(_scanner.tokenValue());
      } else if(token == ATOM) {
          Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
          if(_scanner.currentChar() == '('){
            _scanner.nextToken();
            vector<Term *> terms = getArgs();
            if(_currentToken == ')')
             return new Struct(*atom,terms);
          }else{
            return atom;
          }
      } else if(token == 91){
          vector<Term *> _elements = getElements();
           return new List(_elements);
         }

        else {
          Term *term = new Term();
          return term;
        }
    }


    vector<Term *> getArgs(){
          Term* term = createTerm();
          vector<Term *> args;
          if(term->symbol() == ""){
            return args;
          }
          args.push_back(term);
          while((_currentToken = _scanner.nextToken()) == ','){
            args.push_back(createTerm());
          }

          return args;
    }

    vector<Term *> getElements(){
          Term* term = createTerm();
          vector<Term *> elements;
          elements.push_back(term);

          while((_currentToken = _scanner.nextToken()) == ','){
            elements.push_back(createTerm());
          }
          return elements;
    }
  private:
    Scanner _scanner;
    int _currentToken;
};


#endif

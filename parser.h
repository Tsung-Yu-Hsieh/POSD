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
      //std::cout << _scanner.currentChar() << '\n';

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
        //std::cout << _scanner.position() << '\n';
        if(_scanner.nextToken() == 93)
          return new List();
      } else {
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


  private:
    Scanner _scanner;

    int _currentToken;
};


#endif

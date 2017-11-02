#include "parser.h"

/*Term* Parser::createTerm(){
  int token = _scanner.nextToken();
  if(token == VAR) {
    return new Variable(symtable[_scanner.tokenValue()].first);
  } else if(token == NUMBER) {
    return new Number(_scanner.tokenValue());
  } else if(token == ATOM) {
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.nextToken() == '('){
        vector<Term *> terms = getArgs();
        return new Struct(*atom,terms);
      }else{
        return atom;
      }
  } else {
      return NULL;
    }
}

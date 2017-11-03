#include "parser.h"

Parser::Parser(Scanner scanner){
  _scanner = scanner;
}
Term* Parser::createTerm(){
  int token = _scanner.nextToken();
  //std::cout << _scanner.position() << '\n';
  //std::cout << token << '\n';
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
      return NULL;
    }
}


vector<Term *> Parser::getArgs(){
      Term* term = createTerm();
      vector<Term *> args;
      args.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ','){
        args.push_back(createTerm());
      }
      return args;
}

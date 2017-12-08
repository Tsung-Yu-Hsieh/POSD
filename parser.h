#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "number.h"
#include "utParser.h"
#include "node.h"
#include <stack>
stringstream ss;
using namespace std;
class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _scanner1(scanner),_scanner2(scanner), _terms(){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }



    return nullptr;
  }
  Operators createOperator(){
      if(_currentToken == '='){
        return EQUALITY;
      }
      else if(_currentToken == ','){
        return COMMA;
      }
      else if(_currentToken == ';'){
        return SEMICOLON;
      }

  }
  Term* createOperators(){
    if(_currentToken == '='){
      return new Term("=");
    }
    else if(_currentToken == ','){
      return new Term(",");
    }
    else if(_currentToken == ';'){
      return new Term(";");
    }
  }


  void matchings(){
     _terms.push_back(createTerm());
    while((_currentToken = _scanner.nextToken()) == '=' || _currentToken == ',' || _currentToken == ';') {
      _operatorst.push_back(createOperators());
      _operators.push_back(createOperator());
      _terms.push_back(createTerm());
    }
    for(int i=0;i<_terms.size();i++){
      _s.push(_terms[i]);
    }
    for(int i=0;i<_operatorst.size();i++){
      _t.push(_operatorst[i]);
      _u.push(_operators[i]);
    }
  }

  Node* smallTree(){
      Node* _rightNode = new Node(TERM,_s.top(),nullptr,nullptr);
      _s.pop();
      Node* _leftNode = new Node(TERM,_s.top(),nullptr,nullptr);
      _s.pop();
      Node* _rootNode = new Node(_u.top(),_t.top(),_leftNode,_rightNode);
      _t.pop();
      _u.pop();

      return _rootNode;
  }

  Node* mediumTree(){
    Node* _rightNode1 = smallTree();
    Node* _rootNode1 = new Node(_u.top(),_t.top(),nullptr,_rightNode1);
    _t.pop();
    Node* _leftNode1 = smallTree();
    _rootNode1->left = _leftNode1;
    return _rootNode1;
  }
  Node* bigTree(){
    Node* _rightNode1 = mediumTree();
    Node* _rootNode1 = new Node(_u.top(),_t.top(),nullptr,_rightNode1);
    _t.pop();
    Node* _leftNode1 = smallTree();
    _rootNode1->left = _leftNode1;
    return _rootNode1;
  }

  Node* expressionTree(){
    if(_t.size() == 1){
      _RootNode = smallTree();
      return _RootNode;
    }
    else if(_t.size() == 3){
      _RootNode = mediumTree();
      return _RootNode;
    }
    else{
      _RootNode = bigTree();
      return _RootNode;
    }
  }


  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    getArgs();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    getArgs();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }
  vector<Operators > & getOperators() {
    return _operators;
  }
private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void getArgs() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  vector<Term *> _operatorst;
  vector<Operators > _operators;
  Scanner _scanner;
  Scanner _scanner1;
  Scanner _scanner2;
  int _currentToken;
  int _currentToken1;
  Node* _RootNode;
  stack <Term*> _s;
  stack <Term*> _t;
  stack <Operators> _u;

};
#endif

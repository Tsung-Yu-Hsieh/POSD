#ifndef PARSER_H
#define PARSER_H
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

  void matchings(){
     _terms.push_back(createTerm());
    while((_currentToken = _scanner.nextToken()) == '=' || _currentToken == ',' || _currentToken == ';') {
      _operators.push_back(createOperator());
      _terms.push_back(createTerm());
    }

  }
  Node* lsubTree(){
    Node* _leftNode = new Node(TERM,_terms[0],nullptr,nullptr);
    Node* _rightNode = new Node(TERM,_terms[1],nullptr,nullptr);
    Node* _rootNode = new Node(_operators[0],nullptr,_leftNode,_rightNode);

    return _rootNode;
  }
  Node* rsubTree(){
    Node* _leftNode = new Node(TERM,_terms[2],nullptr,nullptr);
    Node* _rightNode = new Node(TERM,_terms[3],nullptr,nullptr);
    Node* _rootNode = new Node(_operators[0],nullptr,_leftNode,_rightNode);

    return _rootNode;
  }
  Node* rsubTree1(){
    Node* _leftNode = new Node(TERM,_terms[4],nullptr,nullptr);
    Node* _rightNode = new Node(TERM,_terms[5],nullptr,nullptr);
    Node* _rootNode = new Node(_operators[0],nullptr,_leftNode,_rightNode);

    return _rootNode;
  }
  Node* rcsubTree(){
    Node* _leftNode = rsubTree();
    Node* _rightNode = rsubTree1();
    Node* _rootNode = new Node(_operators[1],nullptr,_leftNode,_rightNode);
    return _rootNode;
  }
  Node* expressionTree(){
    if(_operators[3] == 1){
        _RootNode = new Node(_operators[1],nullptr,lsubTree(),rcsubTree());
        return _RootNode;
    }

    for(vector<Operators>::iterator it = _operators.begin();it!=_operators.end();it++){

      if(*it == 2){
        if(*(++it) == 1){
          _RootNode = new Node(_operators[1],nullptr,lsubTree(),rsubTree());

        }
        else{
        _RootNode = lsubTree();
        }
        return _RootNode;
      }

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
  vector<Operators > _operators;
  Scanner _scanner;
  Scanner _scanner1;
  Scanner _scanner2;
  int _currentToken;
  int _currentToken1;
  Node* _RootNode;

};
#endif

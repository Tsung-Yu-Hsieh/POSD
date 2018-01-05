#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include <string>
#include <map>
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
#include "exp.h"
//stringstream ss;
using namespace std;

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _scanner1(scanner),_scanner2(scanner), _terms(){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      if(_scanner.currentChar1() == ';'){
        return new Variable(symtable[_scanner.tokenValue()].first);
      }
      l_it = _mapv.find(symtable[_scanner.tokenValue()].first);
      if(l_it == _mapv.end()) {
        Variable * v = new Variable(symtable[_scanner.tokenValue()].first);
      _mapv.insert(std::pair<string, Variable*>(symtable[_scanner.tokenValue()].first, v));
      std::cout << v << '\n';
      return v;
      }
      else{
        std::cout << l_it->second << '\n';
        return l_it->second;
      }
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
  Exp* getExpressionTree(){
    return _expStack.top();
  }

  void buildExpression(){
    disjunctionMatch();
    restDisjunctionMatch();
    restDisjunctionMatch();
    if(createTerm() != nullptr || _currentToken != '.'){

      if(_expStack.empty()){
        Term* t = _tterms[0];
        throw string(t->symbol()+" does never get assignment");
      }
     else{
      throw string("Missing token '.'");
    }
  }

}

  void restDisjunctionMatch(){
    std::cout << 1 << '\n';
    if(_scanner.currentChar() == ';'){
      std::cout << "/* message */" << '\n';
      createTerm();
      disjunctionMatch();
      Exp *right = _expStack.top();
      _expStack.pop();
      Exp *left = _expStack.top();
      _expStack.pop();
      _expStack.push(new DisjExp(left,right));
      _expStack.top()->evaluate();
      restConjunctionMatch();
    }
  }
  void disjunctionMatch(){
    conjunctionMatch();
    restConjunctionMatch();
  }
  void restConjunctionMatch() {
    if(_scanner.currentChar() == ','){
      createTerm();
      if(_scanner.currentChar() == '.'){
        throw string("Unexpected ',' before '.'");
      }
      conjunctionMatch();
      Exp *right = _expStack.top();
      _expStack.pop();
      Exp *left = _expStack.top();
      _expStack.pop();
      _expStack.push(new ConjExp(left,right));
      _expStack.top()->evaluate();
      restConjunctionMatch();
    }
  }
  void conjunctionMatch() {
    Term* left = createTerm();
    _tterms.push_back(left);
    if(createTerm() == nullptr && _currentToken == '='){
      Term* right = createTerm();
      _tterms.push_back(right);
      result += right->symbol();
      _expStack.push(new MatchExp(left,right));
      state = _expStack.top()->evaluate();

    }
    if(_currentToken == ';'){
      throw string("Unexpected ';' before '.'");
    }
    if(_currentToken == ','){
      throw string("Unexpected ',' before '.'");
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
    //std::cout << _currentToken << '\n';
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
  string returnResult(){
    return result;
  }
  string getExpressionResult(){
    return _expStack.top()->getExpressionResult() + ".";
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
        //std::cout << _scanner.currentChar() << '\n';
        if(_scanner.currentChar() == ' '){
          _scanner.skipLeadingWhiteSpace();
          if(_scanner.currentChar() == ';')
           throw string("Unbalanced operator");
        }
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

  stack<Exp*> _expStack;

  vector <Term*> _tterms;
  string result="";
  bool state;

  map<string, Variable*> _mapv;
  map<string ,Variable*>::iterator l_it;


};
#endif

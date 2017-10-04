#include "atom.h"
#include "variable.h"
#include "number.h"

Atom::Atom(){
   _symbol = "";
}

Atom::Atom(string s){
   _symbol = s;
}

string Atom::symbol(){
  return _symbol;
}
string Atom::value(){
  return _value;
}

bool Atom::match(Number n1){
  return false;
}

bool Atom::match(Variable* v){
  v->setValue(_symbol);
  return true;
}

string Atom::result(Variable* r){
  cout << _symbol << " = "<< r->value() << endl;
}

#include "atom.h"
#include "variable.h"

Atom::Atom(string s){
  _symbol = s;
}
string Atom::symbol() const{
  return _symbol;
}

bool Atom::match(Term & term){
  Variable * vps1 = dynamic_cast<Variable *>(&term);
  bool _ret = _assignable;
  if(vps1){
    if(_ret){
      vps1->setValue(_symbol);
      _assignable = false;
    }
  }
  return _ret;
}

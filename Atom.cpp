#include "number.h"
#include "atom.h"
#include "variable.h"
#include <string>

using std::string;
bool Atom::match(Number a){

   return false;
}

bool Atom::match(Variable& v){
  if(v._l){
    _assignable=true;
    v._symbol=_symbol;
    v._l=false;
  }
  else{
    if(v._symbol == _symbol){
      _assignable=true;
    }
    else{
      _assignable=false;
    }

  }
  return _assignable;
}

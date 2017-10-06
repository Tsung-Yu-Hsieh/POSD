#include "atom.h"
#include "variable.h"
#include "number.h"

using namespace std;

string Atom::symbol(){
  return _symbol;
}
string Atom::value(){
  return _value;
}

bool Atom::match(Number n1){
  return false;
}

bool Atom::match(Variable& v){
  if(v.svalue() == ""){
   v.setValue(_symbol);
   v.setBValue();
   return true;
  }
  else {
    if(_symbol == v.svalue()){
    _assignable=true;
  }
  else{
    _assignable=false;
  }
  return _assignable;
 }
}

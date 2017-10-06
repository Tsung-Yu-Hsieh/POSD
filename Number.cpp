#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>

using namespace std;
stringstream ss;

string Number::value(){
 s_value = std::to_string(_value);
 return s_value;
 }

 string Number::symbol(){
   return s_symbol;
 }
bool Number::match(Number a){
  if(_value == a._value)
    _assignable=true;
  else
    _assignable=false;

    return _assignable;
}

bool Number::match(Atom a){
  return false;
}

bool Number::match(Variable V){
 bool _ref = _assignable;
   if(V.a()== 1){
     return false;
   }
   if(_assignable){
       V.setValue(_value);
       _assignable = false;
     }
   return _ref;
}

int Number::ivalue(){
  return _value;
}

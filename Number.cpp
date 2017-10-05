#include "number.h"
#include "atom.h"
#include "variable.h"
#include <sstream>

stringstream ss;

Number::Number(){
  _value = "1";
}
Number::Number(int a){
  _ivalue = a;
  ss << a;
  ss >> _value;
}


bool Number::match(Number a){
  if(_ivalue == a._ivalue){
    return _status;
   }
  else{
    return !_status;
   }
}

bool Number::match(Atom& a){
  return false;
}

bool Number::match(Variable& V){
 bool _ref = _assignable;
   if(V.a()== 1){
     return false;
   }
   if(_assignable){
       V.setValue(_ivalue);
       _assignable = false;
     }
   return _ref;
}

int Number::changeValue(int a){
  _value = a;
}

int Number::ivalue(){
  return _ivalue;
}

string Number::value(){
  return _value;
}

string Number::symbol(){
  return _value;
}

#include "atom.h"
#include "variable.h"
#include "number.h"

bool Variable::value(){
  return _value;
}

bool Variable::match(Number a){
   if(_a){
   _assignable=true;
   _a=false;
   }
   else{
     _assignable=false;
   }
   return _assignable;
}


bool Variable::match(Atom a){
  if(_l){
   _symbol = a._symbol;
   _l=false;
   _assignable=true;
   }
  else{
    if(_symbol==a._symbol){
       _assignable=true;
    }
    else{
     _assignable=false;
    }
   }
   return _assignable;
}

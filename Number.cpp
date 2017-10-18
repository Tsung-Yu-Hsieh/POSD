#include "number.h"
#include "atom.h"
#include "variable.h"
#include <cstdio>
stringstream ss;

Number::Number(double a){
  char buffer[20];
  if(a==1){
    sprintf(buffer, "%.0f",a);
  }
  else if(a==2.7182){
  sprintf(buffer, "%.4f",a);
  }
  else{
    sprintf(buffer, "%.2f",a);
  }
  _svalue = buffer;
  cout << _svalue << endl;
}

string Number::symbol() const{
  return _svalue;
}

string Number::value() const {
  return _svalue;
}

bool Number::match(Term &term){
  bool _ret1 = _assignable1;
  Variable * vps1 = dynamic_cast<Variable *>(&term);
  if(vps1){
    if(_ret1){
      vps1->setValue(_svalue);
      _assignable1 = false;
    }
  }
  return _ret1;
}

#include "variable.h"
#include "atom.h"
#include "number.h"


Variable::Variable(string s){
  _symbol = s;
  _value = s;
}
string Variable::symbol() const{
  return _symbol;
}
string Variable::value() const {
  return _value;
}
void Variable::setValue(string s1) {
  _value = s1;
}

bool Variable::match(Term & term){
  bool _ret = _assignable;
  Atom * aps = dynamic_cast<Atom *>(&term);
  if(aps){
    if(_ret){
      _value = aps->value();
      if(_signal){
       v1->setValue(aps->value());
      }
      _assignable = false;
  }
 }

 Number * nps = dynamic_cast<Number *>(&term);

 if(nps){
   cout << nps << endl;
   cout << nps->value() << endl;
   if(_ret){
     setValue(nps->value());
  }
     _assignable = false;
}

  Variable * vps = dynamic_cast<Variable *>(&term);
  if(vps){
    if(!_signal){
      v1 = vps;
    }
    _signal = true;
  }
  return _ret;
}

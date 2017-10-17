#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <string>
#include "atom.h"
#include "struct.h"
#include "number.h"
using std::string;
using namespace std;

class Variable :public Term{
public:
  Variable(string s):_symbol(s){
    _value = _symbol;
  }
  string _symbol;

  string symbol() const{
    return _symbol;
  }

  string value() const {
    return _value;
  }
  void setValue(string s1) {
    _value = s1;
  }
  bool match(Term & term){
    Atom * aps = dynamic_cast<Atom *>(&term);
    Number * nps = dynamic_cast<Number *>(&term);
    Variable * vps = dynamic_cast<Variable *>(&term);
    //Variable &v = static_cast<Variable &>(term);

    bool _ret = _assignable;
    if(aps){
      if(_ret){
        _value = aps->value();
        if(_signal){
         v1->setValue(aps->value());
        }
        _assignable = false;
    }
   }
   if(nps){
     cout << nps->value() <<endl;
     if(_ret){
       _value = nps->value();
       cout << nps->value() << endl;
       cout << "test1" << endl;
       if(_signal){
         cout << "test2" << endl;
        v1->setValue(nps->value());
        cout << v1->symbol()+ " = " << v1->value() << " " << _symbol+" = " << _value << endl;
        }
        cout << _symbol+ " = " << _value << endl;
       }
       _assignable = false;
  }
  if(vps){
    if(!_signal){
    v1 = vps;
  }
    _signal = true;
  }
    return _ret;
  }

private:
  bool _signal = false;
  string _value;
  Variable *v1;
  bool _assignable = true;
};

#endif

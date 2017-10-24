#include "variable.h"
#include <iostream>

using namespace std;
string Variable::getName() const {
  return "Variable";
}
string Variable::value() const {
  if (_inst)
    return _inst->value();
  else
    return Term::value();
}
bool Variable::match( Term & term ){
  if (this == &term)
    return true;
  if(!_inst){
    cout << "test1" << endl;
    _inst = &term ;
    //cout << _inst->value() << endl;
    return true;
  }
  return _inst->match(term);
}

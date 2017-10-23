#include "variable.h"
#include <iostream>
using namespace std;
string Variable::value() const {
  if (_inst)
    return _inst->value();
  else
    return Term::value();
}
bool Variable::match( Term & term ){
  cout << this->value() << endl;
  if (this == &term){
    cout << "test2" << endl;
    return true;
  }
  if(!_inst){
    _inst = &term ;
    cout << "tset3" << endl;
    return true;
  }
  return _inst->match(term);
}

#include "variable.h"
#include "atom.h"
#include "number.h"

using namespace std;

//Variable::Variable(string s){
  //_symbol = s;
//}
void Variable::setValue(int a){
  _value = a;
}

void Variable::setValue(string a){
  _svalue = a;
}

bool Variable::match(Atom a){
  bool _ref = _assignable;
    if(_assignable){
      _svalue = a.symbol();
      _assignable = false;
    }
    if(_svalue == a.symbol()){
         return true;
      }
    return _ref;
}

bool Variable::match(Number& n){
  bool _ref = _assignable1;
    if(_assignable == false){
      return false;
    }
    if(_assignable1){
    _value = n.ivalue();
    _assignable1 = false;
    return _ref;
    }
   else{
    return _ref;
    }
}

int Variable::value(){
  return _value;
}

string Variable::svalue(){
  return _svalue;
}
string Variable::symbolv(){
  return _symbol;
}

int Variable::a(){
  return _a;
}

int Variable::setBValue(){
  _a = 1;
}

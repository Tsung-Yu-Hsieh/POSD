#include "atom.h"
#include "variable.h"
#include <typeinfo>
#include <iostream>
using namespace std;

bool Term::match(Term & a){
  if (typeid(a) ==  typeid(Variable)){
    cout << "test1" << endl;
    cout << this->symbol() << endl;
    return a.match(*this);
  }
  else{
    cout << "test4" << endl;
    return symbol() == a.symbol();
  }
}

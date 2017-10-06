#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using std::string;

class Atom;
class Number;
class Variable{
public:
  Variable(string s):_symbol(s){}
  string  _symbol;

  bool value();
  bool match(Number a);
  bool match(Atom a);
  bool _l=true;

private:
  bool _value;
  bool _assignable = true;
  bool _a=true;

};

#endif

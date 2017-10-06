#ifndef ATOM_H
#define ATOM_H
#include <string>


using std::string;
class Number;
class Variable;

class Atom{
  public:
    Atom (string s):_symbol(s){}

    string symbol();
    string value();

    bool match(Number n1);
    bool match(Variable& v);

 private:
   string _value;
   string _symbol;
};

#endif

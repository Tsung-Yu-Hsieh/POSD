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
    bool match(Atom a);
    bool match(Number& n);
    int a();
    int value();
    void setValue(int a);
    void setValue(string a);
    void setBValue();
    string svalue();
    string symbolv();

  private:
    int _value;
    string _svalue;
    bool _assignable = true;
    bool _assignable1 = true;
    int _a = 0;
};

#endif

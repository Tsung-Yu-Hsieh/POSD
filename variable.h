#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
using namespace std;
using std::string;

class Atom;
class Number;

class Variable{
  public:

    Variable(string s);

    bool match(Atom a);
    bool match(Number& n);
    int value();
    void setValue(int a);
    void setValue(string a);
    string svalue();
    string symbolv();

  private:
    int _value;
    string _svalue="";
    string  _symbol;
    bool _assignable = true;
    bool _assignable1 = true;
};

#endif

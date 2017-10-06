#ifndef NUMBER_H
#define NUMBER_H
#include <string>

using std::string;

class Atom;
class Variable;

class Number {
  public:
    Number();
    Number(int a);
    Number(string s);
    bool match(Number a);
    bool match(Atom& a);
    bool match(Variable& V);

    int ivalue();
    string value();
    string symbol();

  private:
    int _ivalue;
    string _symbol;
    string _value;
    bool _status = true;
    bool _assignable = true;
};

#endif

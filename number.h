#ifndef NUMBER_H
#define NUMBER_H
#include <string>

using std::string;


class Variable;
class Atom;

class Number {
  public:
    Number(int s):_value(s){}
    int  _value;

    Number(string s):s_symbol(s){}
    string  s_symbol;
    bool match(Number a);
    bool match(Atom a);
    bool match(Variable V);

    int ivalue();
    string value();
    string symbol();

  private:
    string s_value;
    bool _assignable=true;
};

#endif

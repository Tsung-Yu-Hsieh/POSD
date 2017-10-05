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
  

    bool match(Number a);
    bool match(Atom& a);
    bool match(Variable& V);

    int changeValue(int a);
    int ivalue();
    string value();
    string symbol();

  private:
    int _ivalue;
    string _value;
    string _symbol;
    bool _status = true;
    bool _assignable = true;
};

#endif

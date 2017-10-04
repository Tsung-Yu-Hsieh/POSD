#ifndef ATOM_H
#define ATOM_H
#include <string>
using namespace std;

using std::string;
class Number;
class Variable;

class Atom{
  public:
    Atom();
    Atom (string s);
    string symbol();
    string value();

    bool match(Number n1);
    bool match(Variable* v);
    string result(Variable* r);
 private:
   string _value;
   string _symbol;
};

#endif

#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <string>
#include "term.h"
using std::string;
using namespace std;

class Term;


class Variable :public Term{
public:
  Variable(string s);
  string _symbol;

  string symbol() const;
  string value() const;
  void setValue(string s1);

  bool match(Term & term);

private:
  bool _signal = false;
  string _value;
  Variable *v1;
  bool _assignable = true;
};

#endif

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
using std::string;

class Variable : public Term {
public:
  Variable(string s):Term(s), _inst(0){}
  string value() const;
  bool match( Term & term );
  
  string getName() const;
private:
  Term * _inst;
};

#endif

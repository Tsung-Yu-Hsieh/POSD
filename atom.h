#ifndef ATOM_H
#define ATOM_H
#include <string>
#include "term.h"
using std::string;



class Atom : public Term{
  public:
    Atom (string s);
    string symbol() const;

    bool match(Term &term);
    string _symbol;
  private:
    bool _assignable = true;

};


#endif

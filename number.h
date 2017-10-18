#ifndef NUMBER_H
#define NUMBER_H

#include <sstream>
#include <string>
#include "term.h"
using namespace std;



class Number : public Term{
  public:


    Number(double a);

    string symbol() const;

    string value() const;

    bool match(Term &term);

  private:
    string _svalue;
    double _value;
    bool _assignable1 = true;
};

#endif

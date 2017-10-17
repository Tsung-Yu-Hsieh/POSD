#ifndef NUMBER_H
#define NUMBER_H
#include "atom.h"
#include <sstream>

using namespace std;
stringstream ss;
class Number : public Term{
  public:
    Number(double a):_value(a){
      ss << a;
      ss >> _svalue;
    }
    double _value;

    string symbol() const{
      return _svalue;
    }

    string value() const {
      return _svalue;
    }

  private:
    string _svalue;
};

#endif

#ifndef EXP_H
#define EXP_H

#include <vector>
#include <string>

using namespace std;



class Exp{
 public:
  virtual bool evaluate() = 0;
  virtual string getExpressionResult() = 0;
//  virtual Exp* left() = 0;
//  virtual Exp* right() = 0;
};

class MatchExp : public Exp{
 public:
   MatchExp(Term* left,Term* right):_left(left),_right(right){}

   Term* left(){
     return _left;
   }

   Term* right(){
     return _right;
   }

   bool evaluate(){
     return _left->match(*_right);
   }



   string getExpressionResult(){
     if(evaluate()){
       if(_left->symbol() == _right->symbol())
          return "true";

     return _left->symbol() + " = " + _right->value();
      }
      else{
        return "false";
      }

   }

   string match(){
     return "=";
   }

 private:
   Term* _left;
   Term* _right;

};

class ConjExp : public Exp{
  public:
    ConjExp(Exp *left,Exp *right):_left(left),_right(right){}

    Exp* left(){
      return _left;
    }

    Exp* right(){
      return _right;
    }

    bool evaluate(){
      return (_left->evaluate() && _right->evaluate());
    }

    string conj(){
      return ";";
    }

    string getExpressionResult(){
      if(evaluate()){
        if(_left->getExpressionResult() == _right->getExpressionResult()){
          return _left->getExpressionResult();
        }
        if(_left->getExpressionResult() != _right->getExpressionResult() && _left->getExpressionResult() == "true"){
          return _right->getExpressionResult();
        }
        if(_left->getExpressionResult() != _right->getExpressionResult() && _right->getExpressionResult() == "true"){
          return _left->getExpressionResult();
        }
        string s =  _left->getExpressionResult() + ", " + _right->getExpressionResult();

       return _left->getExpressionResult() + ", " + _right->getExpressionResult();
     }
      else
        return "false";
    }

  private:
    Exp* _left;
    Exp* _right;


};

class DisjExp : public Exp{
 public:
  DisjExp(Exp *left,Exp *right):_left(left),_right(right){}

  Exp* left(){
    return _left;
  }

  Exp* right(){
    return _right;
  }

  bool evaluate(){
    return (_left->evaluate() || _right->evaluate());
  }

  string disj(){
    return ";";
  }

  string getExpressionResult(){
    if(evaluate()){
      if(!_right->evaluate()){
        return _left->getExpressionResult();
      }
      return _left->getExpressionResult() + "; " + _right->getExpressionResult();
    }
  }
 private:
  Exp* _left;
  Exp* _right;
};

#endif

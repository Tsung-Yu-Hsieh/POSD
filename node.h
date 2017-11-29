#ifndef NODE_H
#define NODE_H
#include <typeinfo>
#include "parser.h"
#include "scanner.h"
enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};

class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Operators payload;
  Node(Operators op, Term *t, Node *l, Node *r):payload(op), term(t), left(l), right(r) {}

  bool evaluate(){
    if(this->payload == 2){
      if((this->left->term->getName() == "Number") && (this->right->term->getName() == "Number")){
        return false;
      }
      else{
        this->left->term->match(*this->right->term);
      }
    }
    else if(this->left->payload == 2 ){
      if(this->right->payload == 1 ){
        this->left->left->term->match(*this->left->right->term);
        this->right->left->left->term->match(*this->right->left->right->term);
        this->right->right->left->term->match(*this->right->right->right->term);
      }
      else{
        if(this->left->left->term->symbol() == this->right->left->term->symbol()){
          this->left->left->term->match(*this->left->right->term);
          this->left->left->term->match(*this->right->right->term);
        }
        else{
        this->left->left->term->match(*this->left->right->term);
        this->right->left->term->match(*this->right->right->term);
        }
     }
    }

 }


  Term *term;
  Node *left,*right;
private:

};

#endif

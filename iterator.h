#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "list.h"
#include "struct.h"
#include "node.h"
#include <stack>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};
using namespace std;
class NullIterator :public Iterator{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
      return nullptr;
  }
  bool isDone() const{
    return true;
  }

};

class StructIterator :public Iterator {
public:
  friend class Struct;
  StructIterator(Struct *s): _index(0), _s(s) {}
  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }
private:
  //StructIterator(Struct *s): _index(0), _s(s) {}
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->elements(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }
private:
  int _index;
  List* _list;
};

// class BFSIterator : public Iterator{
// public:
//   friend class Struct;
//   void first(){}
//   void next(){}
//   Term* currentItem() const{
//     return nullptr;
//   }
//   bool isDone() const{
//      return true;
//   }
//  private:
//   BFSIterator(Struct *s): _index(0), _s(s) {}
//   int _index;
//   Struct* _s;
// };
class DFSIterator : public Iterator{
public:
  friend class Node;

  void first(){
    term = _root->term;
    _s.push(_root);
  }
  void next(){



  }
  Term* currentItem() const{
    return term;
  }
  bool isDone() const{
    if(_s.empty())
     return true;
    else
     return false;
  }
private:
 DFSIterator(Node *root): _root(root) {}
 Node * _root;
 Term * term;
 stack<Node *> _s;
};
#endif

#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "list.h"
#include "struct.h"
#include "node.h"
#include <stack>
#include <vector>
using namespace std;



template <class T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
  //virtual void set(int, T);
};


class NullIterator :public Iterator <Term*> {
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


class StructIterator :public Iterator <Term*>  {
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


class ListIterator :public Iterator <Term*> {
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

class BFSIterator : public Iterator<Term*> {
public:
  friend class Struct;
  friend class List;
  void BFS(Term* t,int index){

  }
  void first() {
    if(e == 0){
    for(int i=0;i<_s->arity();i++)
     BFS(_s->args(i),_index);
    _index = 0;
     }
    if(e == 1){
       std::cout << "/* message */" << '\n';
       for(int i=0;i<_l->arity();i++)
        BFS(_l->elements(i),_index);
       _index = 0;
     }

  }

  Term* currentItem() const {
    return v[_index];
  }

  bool isDone() const {
    return _index >= v.size();
  }

  void next() {
    _index++;
  }
private:
  BFSIterator(Struct *s): _index(0), _s(s), e(0){}
  BFSIterator(List *l): _index(0), _l(l), e(1){}
  int e;
  int _index;
  Struct* _s;
  List* _l;
  vector<Term*> v;

};


class DFSIterator : public Iterator <Term*> {
public:
  friend class Struct;
  friend class List;

  void DFS(Term* t,int index){
    Struct *s = dynamic_cast<Struct *>(t);
    List *l  = dynamic_cast<List *>(t);
    Atom *a = dynamic_cast<Atom *>(t);

    if(s){
      v.push_back(&s->name());
      Iterator<Term *> *it = s->createIterator();
      for(it->first();!it->isDone();it->next()){
        v.push_back(it->currentItem());
        List *l =  dynamic_cast<List *>(it->currentItem());
        Struct *s = dynamic_cast<Struct *>(it->currentItem());
        if(l){
          v.pop_back();
          DFS(l,0);
        }
        else if(s){
          v.pop_back();
          DFS(s,0);
        }

      }
    }
    else if(l){
      v.push_back(l->name());
      Iterator<Term *> *it = l->createIterator();
      for(it->first();!it->isDone();it->next()){
        v.push_back(it->currentItem());
        List *l =  dynamic_cast<List *>(it->currentItem());
        Struct *s = dynamic_cast<Struct *>(it->currentItem());
        if(l){
          v.pop_back();
          DFS(l,0);
        }
        else if(s){
          v.pop_back();
          DFS(s,0);
        }
      }
    }
    else if(a){
      v.push_back(a);
    }

  }
  void first() {
    if(e == 0){
    for(int i=0;i<_s->arity();i++)
     DFS(_s->args(i),_index);
    _index = 0;
     }
    if(e == 1){
       std::cout << "/* message */" << '\n';
       for(int i=0;i<_l->arity();i++)
        DFS(_l->elements(i),_index);
       _index = 0;
     }
     for(int i=0;i<v.size();i++){
       std::cout << "v[" << i << "] :";
      std::cout << v[i]->symbol() << '\n';
    }
  }

  Term* currentItem() const {
    return v[_index];
  }

  bool isDone() const {
    return _index >= v.size();
  }

  void next() {
    _index++;
  }
private:
  DFSIterator(Struct *s): _index(0), _s(s), e(0){}
  DFSIterator(List *l): _index(0), _l(l), e(1){}
  int e;
  int _index;
  Struct* _s;
  List* _l;
  vector<Term*> v;

};

#endif

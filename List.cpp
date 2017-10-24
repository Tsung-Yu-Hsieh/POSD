#include "list.h"
#include "variable.h"
#include <typeinfo>
#include <iostream>

using namespace std;

Term * List::elements(int index) {
  return _elements[index];
}
string List::symbol() const{
  string _ret = "[";
  std::vector<Term *>::const_iterator it = _elements.begin();
  if(_elements.empty()){
    return "[]";
  }
  for(;it != _elements.end()-1;++it)
    _ret += (*it)->symbol()+", ";
  _ret += (*it)->symbol()+"]";

  return _ret;
}
string List::value() const{
  string _ret = "[";
  std::vector<Term *>::const_iterator it = _elements.begin();
  if(_elements.empty()){
    return "[]";
  }
  for(;it != _elements.end()-1;++it)
    _ret += (*it)->value()+", ";
  _ret += (*it)->value()+"]";

  return _ret;
}

bool List::match(Term& term){
  if(typeid(term)==typeid(List)){
    List *list = static_cast<List*>(&term);
  for(int i=0;i<_elements.size();i++){
      if(_elements[i]->symbol()!=list->elements(i)->symbol()){
        if(typeid(_elements[i])!=typeid(list->elements(i)))
            return false;
      }
    }
  }
  else{
  if(typeid(term)==typeid(Variable))
   return true;
  return symbol() == term.symbol();
  }
      return true;
}

Term * List::head() const{

}
List * List::tail() const{

}

#include "list.h"


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


Term * List::head() const{

}
List * List::tail() const{

}

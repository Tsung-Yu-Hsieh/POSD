#include "node.h"
#include "iterator.h"

Iterator * Node::createDFSIterator(){
    return new DFSIterator(this);
}

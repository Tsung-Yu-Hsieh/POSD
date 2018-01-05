#ifndef UTITERATOR_H
#define UTITERATOR_H

// #include "number.h"
// #include "variable.h"
// #include "iterator.h"
// #include "parser.h"
//
// TEST(iterator, first) {
//     Number one(1);
//     Variable X("X");
//     Variable Y("Y");
//     Number two(2);
//     Struct t(Atom("t"), { &X, &two });
//     Struct s(Atom("s"), { &one, &t, &Y });
//     //StructIterator it(&s);
//     Iterator<Term*> *itStruct = s.createIterator();
//
//     // Iterator& itStruct = it;
//     // ASSERT_EQ(it.first()->symbol());
//     itStruct->first();
//
//     ASSERT_EQ("1", itStruct->currentItem()->symbol());
//     ASSERT_FALSE(itStruct->isDone());
//     itStruct->next();
//     ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
//     ASSERT_FALSE(itStruct->isDone());
//     itStruct->next();
//     ASSERT_EQ("Y", itStruct->currentItem()->symbol());
//     itStruct->next();
//     ASSERT_TRUE(itStruct->isDone());
// }
//
// TEST(iterator, nested_iterator) {
//   Number one(1);
//   Variable X("X");
//   Variable Y("Y");
//   Number two(2);
//   Struct t(Atom("t"), { &X, &two });
//   Struct s(Atom("s"), { &one, &t, &Y });
//   StructIterator it(&s);
//   it.first();
//   it.next();
//   Struct *s2 = dynamic_cast<Struct *>(it.currentItem());
//
//   StructIterator it2(s2);
//   it2.first();
//   ASSERT_EQ("X", it2.currentItem()->symbol());
//   ASSERT_FALSE(it2.isDone());
//   it2.next();
//   ASSERT_EQ("2", it2.currentItem()->symbol());
//   ASSERT_FALSE(it2.isDone());
//   it2.next();
//   ASSERT_TRUE(it2.isDone());
// }
//
// TEST(iterator, firstList) {
//     Number one(1);
//     Variable X("X");
//     Variable Y("Y");
//     Number two(2);
//     Struct t(Atom("t"), { &X, &two });
//     List l({ &one, &t, &Y });
//     Iterator<Term*> *itList = l.createIterator();
//     //ListIterator it(&l);
//     //Iterator* itList = &it;
//      itList->first();
//      ASSERT_EQ("1", itList->currentItem()->symbol());
//      ASSERT_FALSE(itList->isDone());
//      itList->next();
//      ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
//      ASSERT_FALSE(itList->isDone());
//      itList->next();
//      ASSERT_EQ("Y", itList->currentItem()->symbol());
//      itList->next();
//      ASSERT_TRUE(itList->isDone());
// }
//
// TEST(iterator, NullIterator){
//   Number one(1);
//   NullIterator nullIterator(&one);
//   nullIterator.first();
//   ASSERT_TRUE(nullIterator.isDone());
//   Iterator<Term*> * it = one.createIterator();
//   it->first();
//   ASSERT_TRUE(it->isDone());
// }
//
// TEST(iterator, DFSStructIterator_data1){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   Struct combo1(Atom("combo1"),{&bigMac, &coke, &v});
//   Iterator<Term*> *dfsIt = combo1.createDFSIterator();
//   dfsIt->first();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("bun", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("beefPatty", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("shreddedLettuce", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("coke", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[fries1, fries2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_TRUE(dfsIt->isDone());
// }
// TEST(iterator, DFSStructIterator_data2){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   Struct combo1(Atom("combo1"),{&v, &bigMac, &coke});
//   Iterator<Term*> *dfsIt = combo1.createDFSIterator();
//   dfsIt->first();
//   ASSERT_EQ("[fries1, fries2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("bun", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("beefPatty", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("shreddedLettuce", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("coke", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//
//   ASSERT_TRUE(dfsIt->isDone());
//
// }
// TEST(iterator, DFSListIterator_data1){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   List ll({&bigMac, &coke, &v});
//   Iterator<Term*> *dfsIt = ll.createDFSIterator();
//   dfsIt->first();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("bun", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("beefPatty", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("shreddedLettuce", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("coke", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[fries1, fries2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_TRUE(dfsIt->isDone());
//
// }
// TEST(iterator, DFSListIterator_data2){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   List ll({&coke, &v, &bigMac});
//   Iterator<Term*> *dfsIt = ll.createDFSIterator();
//   dfsIt->first();
//   ASSERT_EQ("coke", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[fries1, fries2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("fries2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("bun", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("beefPatty", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("shreddedLettuce", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("pickleSlice2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion1", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//   ASSERT_EQ("onion2", dfsIt->currentItem()->symbol());
//   dfsIt->next();
//
//   ASSERT_TRUE(dfsIt->isDone());
// }
// TEST(iterator, BFSStructIterator_data1){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   Struct combo1(Atom("combo1"),{&bigMac, &coke, &v});
//   Iterator<Term*> *bfsIt = combo1.createBFSIterator();
//   bfsIt->first();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("coke", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[fries1, fries2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("bun", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("beefPatty", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("shreddedLettuce", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_TRUE(bfsIt->isDone());
// }
// TEST(iterator, BFSStructIterator_data2){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   Struct combo1(Atom("combo1"),{&v, &bigMac, &coke});
//   Iterator<Term*> *bfsIt = combo1.createBFSIterator();
//   bfsIt->first();
//   ASSERT_EQ("[fries1, fries2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("coke", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("bun", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("beefPatty", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("shreddedLettuce", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//
//
//   ASSERT_TRUE(bfsIt->isDone());
// }
// TEST(iterator, BFSListIterator_data1){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   List ll({&bigMac, &coke, &v});
//   Iterator<Term*> *bfsIt = ll.createBFSIterator();
//   bfsIt->first();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("coke", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[fries1, fries2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("bun", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("beefPatty", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("shreddedLettuce", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//
//   ASSERT_TRUE(bfsIt->isDone());
// }
// TEST(iterator, BFSListIterator_data2){
//   Atom bun("bun");
//   Atom beefPatty("beefPatty");
//   Atom shreddedLettuce("shreddedLettuce");
//   Atom pickleSlice1("pickleSlice1");
//   Atom pickleSlice2("pickleSlice2");
//   Atom onion1("onion1");
//   Atom onion2("onion2");
//   Atom coke("coke");
//   Atom fries1("fries1");
//   Atom fries2("fries2");
//   List l({&pickleSlice1, &pickleSlice2});
//   List u({&onion1, &onion2});
//   List v({&fries1, &fries2});
//   Struct bigMac(Atom("bigMac"),{&bun, &beefPatty, &shreddedLettuce, &l, &u});
//   List ll({&coke, &v, &bigMac});
//   Iterator<Term*> *bfsIt = ll.createBFSIterator();
//   bfsIt->first();
//   ASSERT_EQ("coke", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[fries1, fries2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("bigMac(bun, beefPatty, shreddedLettuce, [pickleSlice1, pickleSlice2], [onion1, onion2])", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("fries2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("bun", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("beefPatty", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("shreddedLettuce", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[pickleSlice1, pickleSlice2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("[onion1, onion2]", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("pickleSlice2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion1", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//   ASSERT_EQ("onion2", bfsIt->currentItem()->symbol());
//   bfsIt->next();
//
//   ASSERT_TRUE(bfsIt->isDone());
// }


#endif

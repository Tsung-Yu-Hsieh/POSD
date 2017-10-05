#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"

#include <iostream>
using namespace std;

//test Number.value()
TEST (Number,ctor) {
  Number Number(1);
  ASSERT_EQ("1",Number.value());
}
//test Number.symbol()
TEST (Number, symbol) {
  Number Number("1");
  ASSERT_EQ("1",Number.symbol());

}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
  Number X(25);
  Number Y(25);
  ASSERT_TRUE(X.match(Y));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number X(25);
  Number Y(0);
  ASSERT_FALSE(X.match(Y));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
  Number num(25);
  Atom tom("tom");
  ASSERT_FALSE(num.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  Number num(25);
  Variable X("X");
  ASSERT_TRUE(num.match(X));
  //ASSERT_EQ(25,X.value());
}

//?- tom=25.
//false.

TEST (Atom, matchFailureDiffConstant) {
  Atom tom("tom");
  Number num(25);
  ASSERT_FALSE(tom.match(num));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  Atom tom("tom");
  Variable X("X");
  ASSERT_TRUE(tom.match(X));
  cout << X.symbolv() << " = " << tom.symbol() << endl;
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  Variable X("X");
  Atom tom("tom");
  ASSERT_TRUE(X.match(tom));
  ASSERT_TRUE(tom.match(X));
  cout << X.symbolv() << " = " << tom.symbol() << endl;
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
  Variable X("X");
  Atom jerry("jerry");
  Atom tom("tom");
  ASSERT_TRUE(X.match(jerry));
  ASSERT_EQ("jerry",X.svalue());
  ASSERT_TRUE(tom.match(X));
}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
  Variable X("X");
  Number num(5);
  ASSERT_TRUE(X.match(num));
  cout << X.symbolv() << " = " << num.ivalue() << endl;
}

// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
  Variable X("X");
  Number num(25);
  Number num1(100);
  ASSERT_TRUE(X.match(num));
  ASSERT_FALSE(X.match(num1));
}

// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
  Variable X("X");
  Atom tom("tom");
  Number num(25);
  X.match(tom);
  ASSERT_FALSE(X.match(num));
}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
  Atom tom("tom");
  Variable X("X");
  Number num(25);
  tom.match(X);
  ASSERT_FALSE(num.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){
  Variable X("X");
  Atom tom("tom");
  ASSERT_TRUE(X.match(tom));
  ASSERT_TRUE(X.match(tom));
}
#endif

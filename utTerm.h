#ifndef UTTERM_H
#define UTTERM_H

#include "variable.h"
#include "atom.h"
#include "number.h"



//test Number.value()
TEST (Number, ctor) {
  Number Number(1);
  EXPECT_EQ("1",Number.value());
}
//test Number.symbol()
TEST (Number, symbol) {
  Number num(1);
  EXPECT_EQ("1",num.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
  Number X(25);
  Number Y(25);
  EXPECT_TRUE(X.match(Y));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number X(25);
  Number Y(0);
  EXPECT_FALSE(X.match(Y));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
  Number num(25);
  Atom tom("tom");
  EXPECT_FALSE(num.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  Number num(25);
  Variable X("X");
  EXPECT_TRUE(num.match(X));

}

//?- tom=25.
//false.

TEST (Atom, matchFailureDiffConstant) {
  Atom tom("tom");
  Number num(25);
  EXPECT_FALSE(tom.match(num));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  Atom tom("tom");
  Variable X("X");
  tom.match(X);
  EXPECT_EQ("tom",X.svalue());

}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  Variable X("X");
  Atom tom("tom");
  EXPECT_TRUE(X.match(tom));
  EXPECT_TRUE(tom.match(X));

}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
  Variable X("X");
  Atom jerry("jerry");
  Atom tom("tom");
  EXPECT_TRUE(X.match(jerry));
  EXPECT_EQ("jerry",X.svalue());
  EXPECT_FALSE(tom.match(X));
}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
  Variable X("X");
  Number num(5);
  EXPECT_TRUE(X.match(num));
}

// ?- X=25, X= 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
  Variable X("X");
  Number num(25);
  Number num1(100);
  EXPECT_TRUE(X.match(num));
  EXPECT_FALSE(X.match(num1));
}

// ?- X=tom, X= 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
  Variable X("X");
  Atom tom("tom");
  Number num(25);
  X.match(tom);
  EXPECT_FALSE(X.match(num));
}
//?- tom=X, 25=X.
//false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
  Atom tom("tom");
  Variable X("X");
  Number num(25);
  tom.match(X);
  EXPECT_FALSE(num.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Variable, reAssignTheSameAtom){
  Variable X("X");
  Atom tom("tom");
  EXPECT_TRUE(X.match(tom));
  EXPECT_TRUE(X.match(tom));
}
#endif

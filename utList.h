#ifndef UTLIST_H
#define UTLIST_H

#include <string>
#include <iostream>
using namespace std;
using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "term.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  std::vector<Term *> v = {};
  List l(v);
  EXPECT_EQ("[]",l.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number _num1(8128);
  Number _num2(496);
  std::vector<Term *> v = {&_num2,&_num1};
  List l(v);
  EXPECT_EQ("[496, 8128]",l.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom terence_tao("terence_tao");
  Atom alan_mathison_turing("alan_mathison_turing");
  std::vector<Term *> v = {&terence_tao,&alan_mathison_turing};
  List l(v);
  EXPECT_EQ("[terence_tao, alan_mathison_turing]",l.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable X("X");
  Variable Y("Y");
  std::vector<Term *> v = {&X,&Y};
  List l(v);
  EXPECT_EQ("[X, Y]",l.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Atom tom("tom");
  Number num1(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  List l(v);
  EXPECT_FALSE(l.match(tom));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Number num1(8128);
  Number num2(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num2,&X,&terence_tao};
  List l(v);
  EXPECT_FALSE(l.match(num1));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Number num1(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v1 = {&X};
  Struct s(Atom("s"),v1);
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  List l(v);
  EXPECT_FALSE(l.match(s));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Number num1(496);
  Variable X("X");
  Variable Y("Y");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  List l(v);
  EXPECT_TRUE(Y.match(l));
  EXPECT_EQ("[496, X, terence_tao]",Y.value());
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Number num1(496);
  Variable X("X");
  Variable Y("Y");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  List l(v);
  EXPECT_TRUE(X.match(l));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Number num1(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  List l(v);
  List l1(v);
  EXPECT_TRUE(l.match(l1));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Number num1(496);
  Variable X("X");
  Variable Y("Y");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  std::vector<Term *> v1 = {&num1,&Y,&terence_tao};
  List l(v);
  List l1(v1);
  EXPECT_TRUE(l.match(l1));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
  Number num1(496);
  Number num2(8128);
  Variable X("X");
  Atom terence_tao("terence_tao");
  std::vector<Term *> v = {&num1,&X,&terence_tao};
  std::vector<Term *> v1 = {&num1,&num2,&terence_tao};
  List l(v);
  List l1(v1);
  EXPECT_TRUE(l.match(l1));
  EXPECT_EQ("8128",X.value());
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {

}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
//  Atom f("first"), s("second"), t("third");
  //vector<Term *> args = {&f, &s, &t};
//  List l(args);

//  EXPECT_EQ(string("first"), l.head()->symbol());
//  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  //Atom f("first"), s("second"), t("third");
//  vector<Term *> args = {&f, &s, &t};
//  List l(args);

  //EXPECT_EQ(string("second"), l.tail()->head()->value());
  //EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {

}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {

}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {

}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {

}




#endif

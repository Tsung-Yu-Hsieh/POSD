#ifndef UTEXP_H
#define UTEXP_H


#include "atom.h"
#include "variable.h"
#include "exp.h"
#include "parser.h"

// TEST(Exp, matchExp){
//   Atom tom("tom");
//   Variable X("X");
//   MatchExp mExp(&tom, &X);
//   ASSERT_TRUE(mExp.evaluate());
//   ASSERT_EQ("tom", X.value());
// }
//
// TEST(Exp, BuildExp){
//   Scanner s("tom=X.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_TRUE(p.getExpressionTree()->evaluate());
// }
//
// TEST(Exp, BuildConjunctionExp){
//   Scanner s("X = 2, Y = 3.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_TRUE(p.getExpressionTree()->evaluate());
// }
//
// TEST(Exp, BuildConjunctionExpFail){
//   Scanner s("X = 2, 1 = 3.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_FALSE(p.getExpressionTree()->evaluate());
// }
//
// TEST(Exp, BuildDisjunctionExp){
//   Scanner s("X = 3; Y = 2, Z = 2.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_TRUE(p.getExpressionTree()->evaluate());
// }
//
// TEST(Exp, BuildDisjunctionExpFail){
//   Scanner s("2 = 3; Y = 2, 3 = 1.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_FALSE(p.getExpressionTree()->evaluate());
// }
//
// TEST(Exp, BuildDisjunctionExpSuc){
//   Scanner s("2 = 3; Y = 2, Z = 2.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_TRUE(p.getExpressionTree()->evaluate());
// }
//
// TEST(Exp, exercise1){
//   Scanner s("X = [Y, tom], Y = marry.");
//   Parser p(s);
//   p.buildExpression();
//   ASSERT_TRUE(p.getExpressionTree());
//   ASSERT_TRUE(p.getExpressionTree()->evaluate());
// }


#endif

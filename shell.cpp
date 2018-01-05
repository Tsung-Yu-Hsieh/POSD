// #include <gtest/gtest.h>
// #include <iostream>
// #include "atom.h"
// #include "variable.h"
// #include "exp.h"
// #include "parser.h"
// #include <string>
//
// using namespace std;
//
// int main(int argc, char **argv)
// {
//   string input;
//   int a = 1;
//   std::cout << "Welcome to SWI-Prolog (threaded, 64 bits, version 7.6.3)" << '\n';
//   cout << "?-" << '\n';
//   while(a==1){
//    getline(cin,input);
//    a++;
//   }
//
//
//   return 0;
// }
#include <gtest/gtest.h>


#include "exception.h"
#include "expression.h"

#include <string.h>
#include "atom.h"
#include "variable.h"
#include "exp.h"
#include "parser.h"

using namespace std;


int main( int argc , char **argv )
{
  string input;
  string finalInput;
  cout << "Welcome to SWI-Prolog (threaded, 64 bits, version 7.6.3)" << '\n';
  cout << "?- ";
    while(getline (cin,input)){
        if(input=="halt."){
          break;
        }
        else if(input.find(".", 0)!=string::npos){
              finalInput=finalInput+input;
              Scanner s(finalInput);
              Parser p(s);
              p.buildExpression();
              string result = p.getExpressionResult();
              std::cout << result << '\n';
              finalInput="";
              result="";
              cout << "?- ";
            }
        else if(input.length()==0){
          cout << "?- ";
        }
        else{
            finalInput=finalInput+input;
          cout << "|   " ;
        }
    }
}

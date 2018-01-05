#include <gtest/gtest.h>
#include <string.h>
#include "atom.h"
#include "parser.h"

using namespace std;

int main( int argc , char **argv )
{
  string input;
  string Input;
  cout << "Welcome to Atom-Prolog!!" << '\n';
  cout << "?- ";
    while(getline (cin,input)){
      if(input.length()==0){
        cout << "?- ";
        }
      else if(input.find(".", 0)!=string::npos){
              Input = Input+input;
              Scanner s(Input);
              Parser p(s);
              p.buildExpression();
              string result = p.getExpressionResult();
              std::cout << result << '\n';
                  Input="";
              result="";
              cout << "?- ";
            }
      else if(input=="halt."){
          break;
        }
        else{
          Input = Input+input;
          cout << "|  " ;
        }
    }
}

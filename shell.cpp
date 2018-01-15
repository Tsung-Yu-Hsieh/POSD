#include <gtest/gtest.h>
#include <string.h>
#include "atom.h"
#include "parser.h"

using namespace std;

int main( int argc , char **argv )
{
 string input;
 string Input;
 string result;
 cout << "Welcome to Atom-Prolog!!" << '\n';
 cout << "?- ";
   while(getline (cin,input)){
       if(input=="halt."){
         break;
       }
       else if(input.find(";")!=-1 && input.find(".") == -1){
         Input = Input + input + " ";
         cout << "|   ";
       }
       else if(input.find(".", 0)!=string::npos){
             Input=Input+input;
             Scanner s(Input);
             Parser p(s);
            try {
              p.buildExpression(); // according to your implementation.
              result = p.getExpressionResult();
            } catch (std::string &msg) {
              result = msg;
            }
             std::cout << result << '\n';
             Input="";
             result="";
             cout << "?- ";
    }
       else if(input.length()==0 && Input.length()==0){
         cout << "?- ";
       }
       else{
         try {
           Input=Input+" "+input;
           Scanner s(Input);
           Parser p(s);
           p.buildExpression(); // according to your implementation.
           result = p.getExpressionResult();
           cout << "|   " ;
         } catch (std::string &msg) {
           result = msg;
           cout << result << '\n';
           std::cout << "|   ";
         }
       }
   }
}

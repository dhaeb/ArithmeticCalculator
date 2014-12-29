#include "ExpressionParser.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){

    string expr;
    while(true){
        cout << "Enter your expression (type in 'quit' to leave the program): ";
        std::getline(cin, expr);
        cout << endl;
        if(expr == "quit"){
            break;
        } else {
            cout << "Input: " << expr << endl;
            cout << "Result is: " << ExpressionParser(expr).parse()->eval().toString() << endl;
        }
    }


}

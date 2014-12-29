#ifndef EXPRESSIONPARSER_H_INCLUDED
#define EXPRESSIONPARSER_H_INCLUDED

#include "Expression.h"
#include "Trim.h"

const char PLUS = '+';
const char SUBS = '-';
const char MULT = '*';
const char DIV = '/';

class ExpressionParser{
    string parsable;
public :
    ExpressionParser(string parsable) : parsable(trim(parsable)){}

    template<class T>
    Expression* parseBiOperator(std::string::size_type index){
        auto beforeOp = getParsable().substr(0, index);
        Expression* e1 = ExpressionParser(beforeOp).parse();
        Expression* e2 = ExpressionParser(getParsable().substr(index + 1)).parse();
        return new T(e1,e2);
    }

    Expression* parse(){
        Expression* result;
        auto indexMult = parsable.find(MULT);
        auto indexDiv = parsable.find(DIV);
        auto indexPlus = parsable.find(PLUS);
        auto indexMinus = parsable.find(SUBS);
        auto indexParenthesis = parsable.find('{');
        if(indexPlus != std::string::npos){
            result = parseBiOperator<Addition>(indexPlus);
        } else if(indexMinus != std::string::npos){
            result = parseBiOperator<Substraction>(indexMinus);
        } else if(indexDiv != std::string::npos){
            result = parseBiOperator<Devision>(indexDiv);
        } else if(indexMult != std::string::npos){
            result = parseBiOperator<Multiplication>(indexMult);
        } else if(indexParenthesis != std::string::npos){
            auto indexClosingParenthesis = getParsable().find('}');
            auto value = stoi(getParsable().substr(0, indexParenthesis),
                              0,
                              stoi(getParsable().substr(indexParenthesis + 1, indexClosingParenthesis)));
            result = new IntExpression(value);
        } else {
            result = new IntExpression(stoi(getParsable(), 0, 10));
        }
        return result;
    }

    string getParsable() const {
        return string(parsable);
    }
};



#endif // EXPRESSIONPARSER_H_INCLUDED

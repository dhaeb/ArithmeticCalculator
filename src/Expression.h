/**
 *  Includes all kinds of expressions to create an abstract syntax tree.
 *  This is the only file you need to adjust.
 */
#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

#include <string>

using std::string;

struct ArithmeticException {

    string reason;

    ArithmeticException(string reason) : reason(reason){}

    string what(){
        return reason;
    }
};

class IntExpression;

struct Expression {
    virtual IntExpression eval() = 0;
    virtual ~Expression(){};
};

class IntExpression : public Expression {
    int n;
public :
    IntExpression(int n) : n(n){}

    IntExpression eval(){
        return *this;
    }

    bool operator==(IntExpression other){
        return this->n == other.n;
    }

    bool operator!=(IntExpression other){
        return not (*this == other);
    }

    IntExpression operator+(IntExpression other){
        return IntExpression(n + other.n);
    }

    IntExpression operator-(IntExpression other){
        return IntExpression(n - other.n);
    }

    IntExpression operator*(IntExpression other){
        return IntExpression(n * other.n);
    }

    IntExpression operator/(IntExpression other){
        if(other.n == 0){
            throw ArithmeticException("Devided by zero");
        }
        return IntExpression(n / other.n);
    }

    string toString(){
        return std::to_string(n);
    }
};

class Addition : public Expression {
    Expression * e1, * e2;
public:
    Addition(Expression* e1, Expression* e2) : e1(e1), e2(e2){}
    IntExpression eval(){
        return e1->eval() + e2->eval();
    };

    ~Addition(){
        delete e1;
        delete e2;
    }
};

class Substraction : public Expression {
    Expression * e1, * e2;
public:
    Substraction(Expression* e1, Expression* e2) : e1(e1), e2(e2){}
    IntExpression eval(){
        return e1->eval() - e2->eval();
    };

    ~Substraction(){
        delete e1;
        delete e2;
    }
};

class Multiplication : public Expression {
    Expression * e1, * e2;
public:
    Multiplication(Expression * e1, Expression * e2) : e1(e1), e2(e2){}
    IntExpression eval(){
        return e1->eval() * e2->eval();
    };

    Multiplication(){
        delete e1;
        delete e2;
    }
};

class Devision : public Expression {
    Expression * e1, * e2;
public:
    Devision(Expression* e1, Expression* e2) : e1(e1), e2(e2){}
    IntExpression eval(){
        return e1->eval() / e2->eval();
    };

    ~Devision(){
        delete e1;
        delete e2;
    }
};

#endif // EXPRESSION_H_INCLUDED

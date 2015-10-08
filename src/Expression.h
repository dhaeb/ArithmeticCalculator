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

    #define impl_operator(op) \
    IntExpression operator op(IntExpression other){ \
        return IntExpression(n op other.n); \
    };

    impl_operator(+)
    impl_operator(-)
    impl_operator(*)

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

class BioperatorExpression : public Expression {
    protected:
    Expression * e1, * e2;

    public:
    BioperatorExpression(Expression* e1, Expression* e2) : e1(e1), e2(e2){}
    virtual IntExpression eval() = 0;

    ~BioperatorExpression(){
        delete e1;
        delete e2;
    }
};

#define BioperatorArithmeticTemplate(Typename, Operator) \
    class Typename : public BioperatorExpression { \
        public: \
            Typename(Expression* e1, Expression* e2) : BioperatorExpression(e1, e2) {} \
            IntExpression eval(){ \
                return e1->eval() Operator e2->eval(); \
            } \
    };

BioperatorArithmeticTemplate(Addition, +)
BioperatorArithmeticTemplate(Substraction, -)
BioperatorArithmeticTemplate(Multiplication, *)
BioperatorArithmeticTemplate(Devision, /)

#endif // EXPRESSION_H_INCLUDED

#include <TestHarness.h>
#include <TestResultStdErr.h>
#include <Expression.h>
#include <ExpressionParser.h>

using namespace std;

TEST (Identity,Test1)
{
    CHECK(IntExpression(1) == IntExpression(1).eval());
    CHECK(IntExpression(1) != IntExpression(2).eval());
    CHECK(IntExpression(2) == IntExpression(1) + IntExpression(1));
    CHECK(IntExpression(1) == IntExpression(1) + IntExpression(0));
    CHECK(IntExpression(1) == IntExpression(1) - IntExpression(0));
    CHECK(IntExpression(-1) == IntExpression(1) - IntExpression(2));
    CHECK(IntExpression(0) == IntExpression(1) * IntExpression(0));
    CHECK(IntExpression(42) == IntExpression(7) * IntExpression(6));
    CHECK(IntExpression(0) == IntExpression(0) / IntExpression(12));
    CHECK(IntExpression(1) == IntExpression(12) / IntExpression(12));
    CHECK(IntExpression(1) == IntExpression(4) / IntExpression(3));

    bool wasThrown = false;
    try {
        IntExpression(4) / IntExpression(0);
    } catch (ArithmeticException e){
        wasThrown =true;
        CHECK("Devided by zero" == e.what());
    }
    CHECK(wasThrown);
    CHECK("3" == IntExpression(3).toString());
    CHECK("-6" == IntExpression(-6).toString());
}

TEST (Arithmetic,Test2)
{
    CHECK(IntExpression(2) == Addition(new IntExpression(1), new IntExpression(1)).eval());
    CHECK(IntExpression(3) == Addition(new Addition(new IntExpression(1), new IntExpression(1)), new IntExpression(1)).eval());
    CHECK(IntExpression(2) == Multiplication(new IntExpression(2), new IntExpression(1)).eval());
    CHECK(IntExpression(1) == Substraction(new Addition(new IntExpression(1), new IntExpression(1)), new IntExpression(1)).eval());
    CHECK(IntExpression(2) == Devision(new Addition(new IntExpression(1), new IntExpression(1)), new IntExpression(1)).eval());
}

TEST (ParserNumbers,Test3){
    auto result = ExpressionParser("1").parse();
    CHECK(IntExpression(1) == result->eval());
    result = ExpressionParser("2").parse();
    CHECK(IntExpression(2) == result->eval());

}

TEST (ParserArithmetic,Test4){
    auto assertExpressionParserCanParse = [&](IntExpression&& expected,
                                             const char * parsable) -> void {
        auto result = ExpressionParser(parsable).parse();
        CHECK(expected == result->eval());
    };
    assertExpressionParserCanParse(IntExpression(2), "1 + 1");
    assertExpressionParserCanParse(IntExpression(-3), "1 - 4");
    assertExpressionParserCanParse(IntExpression(16), "4 * 4");
    assertExpressionParserCanParse(IntExpression(1), "4 / 4");
    assertExpressionParserCanParse(IntExpression(404), "4 + 4 * 100");
}

TEST (ParserBasis,Test5){
    auto result = ExpressionParser("10{16}").parse();
    CHECK(IntExpression(16) == result->eval());
}

TEST (ParserBasis,Test6){
    auto result = ExpressionParser("10{16} * 100 / 10000{2}").parse();
    CHECK(IntExpression(100) == result->eval());
}

int main()
{
    TestResultStdErr result;
    TestRegistry::runAllTests(result);
    return (result.getFailureCount());
}




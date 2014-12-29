#include <TestHarness.h>
#include <TestResultStdErr.h>
#include <Expression.h>
#include <ExpressionParser.h>

using namespace std;

TEST (IntExpression,Test1)
{
    // Here you have to add some tests
    // for the production code which you will need to write
    // in order to get the program working!!!
}

#ifdef RUN_OTHER_TESTS // you can delete this when you want to run the other tests
                       // DON'T FORGET ALSO TO DELETE THE ENDIF OF THE MACRO!

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

#endif // OTHER_TESTS

int main()
{
    TestResultStdErr result;
    TestRegistry::runAllTests(result);
    return (result.getFailureCount());
}




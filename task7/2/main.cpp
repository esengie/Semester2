#include <exceptionalSetTest.h>

int main()
{
    ExceptionalSetTest test;
    QTest::qExec(&test);
    return 0;
}

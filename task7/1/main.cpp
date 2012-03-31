#include "exceptionTestTest.h"

int main()
{
    ExceptionTestTest test;
    QTest::qExec(&test);
    return 0;
}

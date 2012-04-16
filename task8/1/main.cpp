#include "bagTest.h"
#include <QTest>
int main()
{
    BagTest test;
    QTest::qExec(&test);
    return 0;
}

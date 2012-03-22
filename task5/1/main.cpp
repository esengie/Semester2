#include "stringListTest.h"
#include "hashChangeableTest.h"
int main()
{
    StringListTest test;
    HashChangeableTest test2;
    QTest::qExec(&test);
    QTest::qExec(&test2);

}

//#include <vectorTest.h>
#include "vector.h"
int main()
{
    std::vector<int> nm(4,5);
    Vector<int> t2(nm);
    std::vector<int>::size_type m = 5;
    Vector<int> t(m);
    Vector<int> t3 = t + t2;
    Vector<int> t4 = t3.scalar(t2);
    //VectorTest test;
    //QTest::qExec(&test);
    return 0;
}

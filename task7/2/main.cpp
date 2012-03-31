#include <exceptionalSet.h>

int main()
{
    Set<int>* mSet = new ExceptionalSet<int>();
    Set<std::string>* nSet = new ExceptionalSet<std::string>();

    std::string lk = "sdJ";
    nSet->add(lk);
    mSet->add(43);
    std::string fg = "sdfsd";
    nSet->deleteVal(fg);
    nSet->add(fg);
    nSet->deleteVal(fg);
    mSet->deleteVal(45);
    mSet->add(32);
    mSet->deleteVal(32);

//    ListSetTest test;
//    QTest::qExec(&test);
    return 0;
}

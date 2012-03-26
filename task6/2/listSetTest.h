#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "listSet.h"

class ListSetTest : public QObject
{
    Q_OBJECT
public:
    explicit ListSetTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mSet = new ListSet<int>();
        nSet = new ListSet<std::string>();
    }
    void cleanup()
    {
        delete mSet;
        delete nSet;
    }

    void testLookup_and_AddString()
    {
        std::string lk = "sdJ";
        QVERIFY(!nSet->lookup(lk));
        nSet->add(lk);
        QVERIFY(nSet->lookup(lk));
    }
    void testLookup_and_AddNumber()
    {
        QVERIFY(!mSet->lookup(45));
        mSet->add(43);
        QVERIFY(mSet->lookup(43));
    }
    void testDeleteValueString()
    {
        std::string fg = "sdfsd";
        nSet->deleteVal(fg);
        nSet->add(fg);
        QVERIFY(nSet->lookup(fg));
        nSet->deleteVal(fg);
        QVERIFY(!nSet->lookup(fg));
    }
    void testDeleteValueNumber()
    {
        mSet->deleteVal(45);
        mSet->add(32);
        QVERIFY(mSet->lookup(32));
        mSet->deleteVal(32);
        QVERIFY(!mSet->lookup(32));
    }

private:
    ListSet<int>* mSet;
    ListSet<std::string>* nSet;
};


//QTESTMAIN(ListSetTest);

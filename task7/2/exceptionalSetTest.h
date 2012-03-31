#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "exceptionalSet.h"

class ExceptionalSetTest : public QObject
{
    Q_OBJECT
public:
    explicit ExceptionalSetTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mSet = new ExceptionalSet<int>();
        nSet = new ExceptionalSet<std::string>();
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
        try
        {
            nSet->add(lk);
            nSet->add(lk);
        }
        catch(ExceptionalSet<std::string>::AddExisting)
        {
            QWARN("Already there");
        }
        QVERIFY(nSet->lookup(lk));
    }
    void testLookup_and_AddNumber()
    {
        QVERIFY(!mSet->lookup(45));
        try
        {
            mSet->add(43);
            mSet->add(43);
        }
        catch(ExceptionalSet<int>::AddExisting)
        {
            QWARN("Already there, which is a good thing");
        }
        QVERIFY(mSet->lookup(43));
    }
    void testDeleteValueString()
    {
        std::string fg = "sdfsd";
        try
        {
            nSet->deleteVal(fg);
        }
        catch(ExceptionalSet<std::string>::DeleteFromEmpty)
        {
            QWARN("Works fine");
        }
    }
    void testDeleteValueNumber()
    {
        try
        {
            mSet->deleteVal(345);
        }
        catch(ExceptionalSet<int>::DeleteFromEmpty)
        {
            QWARN("Works fine");
        }
    }

private:
    ExceptionalSet<int>* mSet;
    ExceptionalSet<std::string>* nSet;
};


//QTESTMAIN(ExceptionalSetTest);

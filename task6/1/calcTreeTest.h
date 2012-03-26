#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "calcTree.h"
#include <sstream>
#include<stdexcept>

class CalcTreeTest : public QObject
{
    Q_OBJECT
public:
    explicit CalcTreeTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        netty = "(/(*4(+29) 2)";
        mTree = new Operation(netty);
    }
    void cleanup()
    {
        delete mTree;
    }

    void test_Tree_Result()
    {
        try
        {
            int tmp = mTree->result();
            QCOMPARE(tmp,22);
        }
        catch (std::invalid_argument& thm)
        {
            QFAIL("You...you messed up my tests!");
        }
    }
    void test_Tree_Print()
    {
        std::streambuf* buff = std::cout.rdbuf();
        std::cout.rdbuf(bt.rdbuf());
        mTree->print();
        QVERIFY(!bt.str().compare("(/(* 4(+ 2 9)) 2)"));
        std::cout.clear();
        std::cout.rdbuf(buff);
    }

private:
    std::string netty;
    CalcTree* mTree;
    std::stringstream bt;
};


//QTESTMAIN(CalcTreeTest);

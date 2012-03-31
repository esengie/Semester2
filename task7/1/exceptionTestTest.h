#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "exceptionTest.h"
#include <sstream>
#include <stdexcept>

class ExceptionTestTest : public QObject
{
    Q_OBJECT
public:
    explicit ExceptionTestTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void test_Print()
    {
        std::streambuf* buff = std::cout.rdbuf();
        std::cout.rdbuf(bt.rdbuf());

        ExceptionTest* rTest = new ExceptionTest();
        try
        {
            rTest->Snide();
        }
        catch(std::logic_error)
        {
            delete rTest;
        }
        QVERIFY(!bt.str().compare("I'm Aliiiive\n""I'm deeeaaaaaaaaad!!!!!\n"));
        std::cout.clear();
        std::cout.rdbuf(buff);
    }

private:
    std::string netty;
    std::stringstream bt;
};



#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "vector.h"
#include <sstream>

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        std::vector<int>::size_type m = 5;
        std::vector<std::string>::size_type n = 5;
        nVec = new Vector<int>(m);
        stringVec = new Vector<std::string>(n);
    }
    void cleanup()
    {
        delete nVec;
        delete stringVec;
    }
    void testIsNull()
    {
        QVERIFY(nVec->isNull() && stringVec->isNull());
    }

    void test_stdVec_Constructor_and_scalar()
    {
        std::vector<int> nm(4, 5);
        Vector<int> t2(nm);
        QVERIFY(t2.scalar(t2) == 100);
    }
    void test_sum_and_minus_and_assignment()
    {
        std::vector<int> nm(4, 5);
        Vector<int> t2(nm);
        (*nVec) = (*nVec) + t2;
        QVERIFY(nVec->scalar(*nVec) == 100);
        (*nVec) = (*nVec) - t2 - t2;
        //std::stringstream erer;
        //erer << nVec->scalar(*nVec);
        //QWARN(erer.str().c_str());
        QVERIFY(nVec->scalar(*nVec) == 100);
    }
    void testCopyConstructor()
    {
        std::vector<int> nm(4, 5);
        Vector<int> t2(nm);
        Vector<int> t3(t2);
        QVERIFY(t3.scalar(t3) == 100);
    }
private:
    Vector<int>* nVec;
    Vector<std::string>* stringVec;
};

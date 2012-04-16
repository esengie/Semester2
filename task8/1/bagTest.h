#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "bag.h"
#include <string>
#include <sstream>

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void cleanup()
    {
        mSet.clear();
        nSet.clear();
    }
    void testEmpty()
    {
        QVERIFY(nSet.isEmpty());
    }
    void testInsertFindNumeric()
    {
        mSet.insert(34);
        mSet.insert(34);
        mSet.insert(45);
        mSet.insert(3);
        QVERIFY(mSet.find(34) && mSet.find(45) && !mSet.find(0));
    }
    void testEraseNumeric()
    {
        int fg = 46;
        int er = 89;
        int gmnomnom = 90;
        mSet.insert(fg);
        mSet.insert(fg);
        mSet.erase(fg);
        mSet.insert(er);
        mSet.erase(er);
        mSet.insert(gmnomnom);
        mSet.insert(gmnomnom);
        mSet.eraseAll(gmnomnom);
        QVERIFY(mSet.find(fg) && !mSet.find(er) && !mSet.find(gmnomnom));
    }
    void testQuantityNumeric()
    {
        int fg = 46;
        int gmnomnom = 90;
        mSet.insert(fg);
        mSet.insert(fg);
        mSet.insert(fg);
        mSet.insert(gmnomnom);
        mSet.insert(gmnomnom);

        QVERIFY((mSet.quantity(fg) == 3) && (mSet.quantity(gmnomnom) == 2));
    }
    void testInsertFindString()
    {
        std::string tu = "fdhfgjfgjfhgfgf";
        nSet.insert(tu);
        nSet.insert("34");
        nSet.insert("ghjghjhgjg");
        QVERIFY(nSet.find(tu) && !nSet.find("dfgfdgdfh"));
    }
    void testEraseString()
    {
        std::string fg = "John sat on the porch";
        std::string er = "Desperately looking at the skies";
        std::string gmnomnom = "\"I\'m here\" he heard somebody whisper...";
        nSet.insert(fg);
        nSet.insert(fg);
        nSet.erase(fg);
        nSet.insert(er);
        nSet.erase(er);
        nSet.insert(gmnomnom);
        nSet.insert(gmnomnom);
        nSet.eraseAll(gmnomnom);
        QVERIFY(nSet.find(fg) && !nSet.find(er) && !nSet.find(gmnomnom));
    }
    void testQuantityString()
    {

        std::string fg = "46";
        std::string gmnomnom = "90";
        nSet.insert(fg);
        nSet.insert(fg);
        nSet.insert(fg);
        nSet.insert(gmnomnom);
        nSet.insert(gmnomnom);

        QVERIFY((nSet.quantity(fg) == 3) && (nSet.quantity(gmnomnom) == 2));
    }
    void testClear()
    {
        std::string fg = "46";
        std::string gmnomnom = "90";
        nSet.insert(fg);
        nSet.insert(fg);
        nSet.insert(gmnomnom);
        nSet.clear();
        QVERIFY(nSet.isEmpty());
    }
private:
    Bag<int> mSet;
    Bag<std::string> nSet;
};


//QTESTMAIN(BagTest);


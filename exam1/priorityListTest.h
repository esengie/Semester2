#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "priorityList.h"

class PriorityListTest : public QObject
{
    Q_OBJECT
public:
    explicit PriorityListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mList = new PriorityList<int>();
        nList = new PriorityList<std::string>();
    }
    void cleanup()
    {
        delete mList;
        delete nList;
    }
    void testDeletFromEmpty()
    {
        try
        {
            mList->dequeue();
        }
        catch(PriorityList<int>::EmptyList)
        {
            QVERIFY(true);
        }
    }

    void testEnqueueDequeueString()
    {
        std::string fg = "sdfsd";
        std::string fg2 = "sdfs12312312321321231231231323123122312312321d";
        std::string fg3 = "!!!!!!!!!!!!!sdfsd";
        nList->enqueue(fg, 45);
        nList->enqueue(fg2, 78);
        nList->enqueue(fg3, 455);
        QVERIFY(!nList->dequeue().compare(fg3));
        QVERIFY(!nList->dequeue().compare(fg2));

    }
    void testEnqueueDequeueInt()
    {
        int fg = 3;
        int fg2 = 234;
        int fg3 = 99;
        mList->enqueue(fg, 45);
        mList->enqueue(fg2, 78);
        mList->enqueue(fg3, 455);
        QVERIFY(mList->dequeue() == fg3);
        QVERIFY(mList->dequeue() == fg2);
    }

private:
    PriorityList<int>* mList;
    PriorityList<std::string>* nList;
};


//QTESTMAIN(PriorityListTest);


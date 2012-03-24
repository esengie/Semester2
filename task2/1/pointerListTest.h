#ifndef PointerListTest_H
#define PointerListTest_H

#include <QTest>
#include <QObject>
#include <pointerList.h>

class PointerListTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mList = new PointerList();
    }
    void cleanup()
    {
        delete mList;
    }

    void testIsIn_and_Add()
    {
        mList->add(45);
        mList->add(4563);
        mList->add(2333);
        QVERIFY(mList->isIn(4563));
    }
    void testLength()
    {
        mList->add(222);
        mList->add(4563);
        mList->add(2333);
        QVERIFY(mList->length() == 3);
    }
    void testRemove()
    {
        mList->add(4563);
        mList->add(2333);
        mList->remove(4563);
        QVERIFY(!mList->isIn(4563));

    }
private:
    List* mList;
};

#endif // PointerListTest_H

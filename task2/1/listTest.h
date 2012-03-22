#ifndef LISTTEST_H
#define LISTTEST_H

#include <QTest>
#include <QObject>
#include <arrayList.h>
#include <pointerList.h>

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mList = new PointerList();
        mArrList = new ArrayList();
    }
    void cleanup()
    {
        delete mList;
        delete mArrList;
    }

    void testIsIn_and_Add()
    {
        mList->add(45);
        mList->add(4563);
        mList->add(2333);
        mArrList->add(45);
        mArrList->add(4563);
        mArrList->add(2333);
        QVERIFY(mList->isIn(4563));
        QVERIFY(mArrList->isIn(45));
    }
    void testLength()
    {
        mList->add(222);
        mList->add(4563);
        mList->add(2333);
        mArrList->add(45);
        mArrList->add(4563);
        QVERIFY(mList->length() == 3);
        QVERIFY(mArrList->length() == 2);
    }
    void testRemove()
    {
        mList->add(4563);
        mList->add(2333);
        mArrList->add(45);
        mArrList->add(4563);
        mArrList->add(2333);
        mList->remove(4563);
        mArrList->remove(45);
        QVERIFY(!mList->isIn(4563));
        QVERIFY(!mArrList->isIn(45));

    }
private:
    List* mList;
    List* mArrList;
};

#endif // LISTTEST_H

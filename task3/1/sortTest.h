#ifndef SORTTEST_H
#define SORTTEST_H

#include <QObject>
#include <QTest>
#include "quickSort.h"
#include "shitSort.h"
#include "bubbleSort.h"

class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mLength = 10;
        mZeros = 4;
        mArray = new int[mLength];
        for (int i = 0; i < mLength; i++)
        {
            if (i < mLength - mZeros)
                mArray[i] = mLength - i;
            else
                mArray[i] = 0;
        }
    }
    void cleanup()
    {
        delete mArray;
    }
    void testQuickSort()
    {
        QuickSort sorter;
        sorter.sort(mArray, mLength);
        for (int i = 0; i < mLength; i++)
        {
            if (i < mZeros)
                QVERIFY(!mArray[i]);
            else
                QVERIFY(mArray[i] == i + 1);
        }
    }
    void testBubbleSort()
    {
        BubbleSort sorter;
        sorter.sort(mArray, mLength);
        for (int i = 0; i < mLength; i++)
        {
            if (i < mZeros)
                QVERIFY(!mArray[i]);
            else
                QVERIFY(mArray[i] == i + 1);
        }
    }
    void testStoogeSort()
    {
        ShitSort sorter;
        sorter.sort(mArray, mLength);
        for (int i = 0; i < mLength; i++)
        {
            if (i < mZeros)
                QVERIFY(!mArray[i]);
            else
                QVERIFY(mArray[i] == i + 1);
        }
    }


private:
    int mZeros;
    int mLength;
    int* mArray;
};

#endif // SORTTEST_H

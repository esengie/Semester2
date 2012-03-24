#ifndef FirstElemSortTesto_H
#define FirstElemSortTesto_H

#include <QTest>
#include <QObject>
#include <quickSort.h>

class FirstElemSortTest : public QObject
{
    Q_OBJECT
public:
    explicit FirstElemSortTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {

        mSorter = new QuickSort();
        mArray = new int*[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            mArray[i] = new int[SIZE];
        }
        n = 3;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mArray[j][i] = n * i + j;
            }
        }
    }
    void cleanup()
    {
        for (int i = 0; i < SIZE; i++)
        {
            delete [] mArray[i];
        }
        delete mSorter;
        delete [] mArray;
    }

    void testSorter()
    {
        mSorter->sort(mArray, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                QVERIFY(mArray[j][i] == n * i +j);
            }
        }
    }

private:
    int n;
    static const int SIZE = 20;
    Sort* mSorter;
    int** mArray;
};

#endif // FirstElemSortTesto_H

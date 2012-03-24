#ifndef SpiralTest_H
#define SpiralTest_H

#include <QTest>
#include <QObject>
#include <filePrinter.h>
#include <iostream>
#include <sstream>
#include <fstream>

class SpiralTest : public QObject
{
    Q_OBJECT
public:
    explicit SpiralTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        ciin = std::cin.rdbuf();
        coout = std::cout.rdbuf();
        mFilePrinter = new FilePrinter();
        mArray = new int*[SIZE];
        mInput << "tefg.txt";
        std::cin.rdbuf(mInput.rdbuf());
        std::cout.rdbuf(mOutput.rdbuf());
        for (int i = 0; i < SIZE; i++)
        {
            mArray[i] = new int[SIZE];
        }
        n = 3;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mArray[i][j] = n * i + j + 1;
            }
        }
    }
    void cleanup()
    {
        std::cin.rdbuf(ciin);
        std::cout.rdbuf(coout);
        mOutput.close();
        mInput.clear();
        for (int i = 0; i < SIZE; i++)
        {
            delete [] mArray[i];
        }
        delete mFilePrinter;
        delete [] mArray;
    }

    void testSorter()
    {
        int temp;
        mFilePrinter->print(mArray, n);
        for (int i = 1; i <= n; i++)
        {
            mOutput << temp;
            QVERIFY(temp == i);
        }
        mOutput << temp;
        QVERIFY(temp == 6);
        for (int i = n; i > 0; i++)
        {
            mOutput << temp;
            QVERIFY(temp == i);
        }
        mOutput << temp;
        QVERIFY(temp == 4);
        mOutput << temp;
        QVERIFY(temp == 5);
    }

private:
    std::streambuf* coout;
    std::streambuf* ciin;
    std::stringstream mInput;
    std::ofstream mOutput;
    int n;
    static const int SIZE = 20;
    FilePrinter* mFilePrinter;
    int** mArray;
};

#endif // SpiralTest_H

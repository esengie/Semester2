#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "stringList.h"


class StringListTest : public QObject
{
    Q_OBJECT
public:
    explicit StringListTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        listy = new StringList();
    }
    void cleanup()
    {
        delete listy;
    }

    void testInclusions()
    {
        QVERIFY(listy->inclusions() == 0);
        listy->insert("sdk");
        listy->insert("sdkh");
        listy->insert("sdkh");

        QVERIFY(listy->next->inclusions() == 1);
        QVERIFY(listy->next->next->inclusions() == 2);

        listy->deleteVal("sdkh");
        QVERIFY(listy->next->next->inclusions() == 1);
    }

    void testInsert()                                       ///< No test for find because if Insert works it implies that find also works
    {
        listy->insert("sdk");
        listy->insert("sdkh");
        listy->insert("sdkh");

        QVERIFY(!(listy->next->getVal().compare("sdk")));
        QVERIFY(!(listy->next->next->getVal().compare("sdkh")));
    }
    void testDeleteVal()
    {
        listy->insert("sdk");
        listy->insert("sdkh");
        listy->insert("sdkh");
        listy->deleteVal("sdkh");
        QVERIFY(!(listy->next->next->getVal().compare("sdkh")));

        listy->deleteVal("sdk");
        QVERIFY(!(listy->next->getVal().compare("sdkh")));

    }

private:
    StringList* listy;
};

//QTEST_MAIN(StringListTest);




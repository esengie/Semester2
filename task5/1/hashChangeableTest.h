#ifndef HASHCHANGEABLETEST_H
#define HASHCHANGEABLETEST_H

#include <QObject>
#include <QTest>
#include "hashChangeable.h"
#include "someHashFunction.h"

class HashChangeableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashChangeableTest(QObject *parent = 0);
private slots:
    void init()
    {
        mHasher = new SomeHashFunction(13456);
        mHash = new HashChangeable(mHasher, mHasher->ARRAYLENGTH);
    }
    void cleanup()
    {
        delete mHash;
        delete mHasher;
    }
    void testInsert()
    {
         mHash->insert("sdj");
         QVERIFY(mHash->hashe[mHasher->hash("sdj")]->find("sdj"));                       ///< ouch
    }
    void testLookup()
    {
        QVERIFY(!mHash->lookup("sdj"));
        mHash->insert("sdj");
        QVERIFY(mHash->lookup("sdj"));
        mHash->deleteValue("sdj");
        QVERIFY(!mHash->lookup("sdj"));

    }
    void testElementsQuantity()
    {
        QVERIFY(!mHash->elementsQuantity());
        mHash->deleteValue("sd00");
        QVERIFY(!mHash->elementsQuantity());
        mHash->insert("sdj");
        QVERIFY(mHash->elementsQuantity() == 1);
        mHash->insert("sdj");
        QVERIFY(mHash->elementsQuantity() == 2);
        mHash->deleteValue("sdj");
        QVERIFY(mHash->elementsQuantity() == 1);
    }
    void testDeleteValue()
    {
        mHash->deleteValue("sd00");
        mHash->insert("asdf");
        mHash->insert("asdf");
        mHash->deleteValue("asdf");
        QVERIFY(mHash->lookup("asdf"));
        mHash->deleteValue("asdf");
        QVERIFY(!mHash->lookup("asdf"));
    }
private:
    HashChangeable* mHash;
    HashFunction* mHasher;
};

#endif // HASHCHANGEABLETEST_H

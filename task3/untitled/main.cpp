//#include <QtGui/QApplication>
//#include "widget.h"
#include "QString"
#include <iostream>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    QString h = "    5";
    char ad = h.toAscii().data()[4];
    std::cout << ad;

    return 0;
}

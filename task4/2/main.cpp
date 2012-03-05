#include <QtGui/QApplication>
#include "calculatorWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorWidget w;
    w.show();

    return a.exec();
}

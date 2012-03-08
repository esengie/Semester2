#ifndef UICALCULATOR_H
#define UICALCULATOR_H


#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <QString>



class Ui_CalculatorWidget
{
public:
    static const int SIZE = 16;

public:
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QPushButton * pushButton[SIZE];
    QLineEdit *lineEdit;


    void setupUi(QWidget *CalculatorWidget)
    {
        if (CalculatorWidget->objectName().isEmpty())
            CalculatorWidget->setObjectName(QString::fromUtf8("CalculatorWidget"));

        CalculatorWidget->resize(400, 300);



        gridWidget = new QWidget(CalculatorWidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 0, 400, 300));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);





        for (int i = 0; i < SIZE; i++)
        {
            pushButton[i] = new QPushButton(gridWidget);
            if (i < 10)
                pushButton[i]->setObjectName(QString("%1").arg(i));
            sizePolicy.setHeightForWidth(pushButton[i]->sizePolicy().hasHeightForWidth());
            pushButton[i]->setSizePolicy(sizePolicy);
            gridLayout->addWidget(pushButton[i], i / 4 + 2, i % 4, 1, 1);
        }
        pushButton[10]->setObjectName("C");
        pushButton[11]->setObjectName("+");
        pushButton[12]->setObjectName("-");
        pushButton[13]->setObjectName("*");
        pushButton[14]->setObjectName("/");
        pushButton[15]->setObjectName("=");

        lineEdit = new QLineEdit(gridWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 4);


        retranslateUi(CalculatorWidget);

        QMetaObject::connectSlotsByName(CalculatorWidget);
    } // setupUi

    void retranslateUi(QWidget *CalculatorWidget)
    {
        CalculatorWidget->setWindowTitle(QApplication::translate("CalculatorWidget", "utipuuuty", 0, QApplication::UnicodeUTF8));

        for (int i = 0; i < 10; i++)
        {
            pushButton[i]->setText(QApplication::translate("CalculatorWidget",
                                                           QString("%1").arg(i).toUtf8().constData(),
                                                           0, QApplication::UnicodeUTF8));
        }
        pushButton[10]->setText(QApplication::translate("CalculatorWidget", "C", 0, QApplication::UnicodeUTF8));
        pushButton[11]->setText(QApplication::translate("CalculatorWidget", "+", 0, QApplication::UnicodeUTF8));
        pushButton[12]->setText(QApplication::translate("CalculatorWidget", "-", 0, QApplication::UnicodeUTF8));
        pushButton[13]->setText(QApplication::translate("CalculatorWidget", "*", 0, QApplication::UnicodeUTF8));
        pushButton[14]->setText(QApplication::translate("CalculatorWidget", "/", 0, QApplication::UnicodeUTF8));
        pushButton[15]->setText(QApplication::translate("CalculatorWidget", "=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi
};

namespace Ui
{
    class CalculatorWidget: public Ui_CalculatorWidget {};
}



#endif // UICALCULATOR_H

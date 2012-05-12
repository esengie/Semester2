#include "ticTacToe.h"

void TicTacToe::setupUI()
{
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("MagnificientNothing"));

    resize(400, 300);



    gridWidget = new QWidget(this);
    gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
    gridWidget->setGeometry(QRect(0, 0, 400, 300));
    gridLayout = new QGridLayout(gridWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);





    for (int i = 0; i < (SIZE - 1); i++)
    {
        pushButton[i] = new QPushButton(gridWidget);
        pushButton[i]->setObjectName(QString("%1").arg(i));
        sizePolicy.setHeightForWidth(pushButton[i]->sizePolicy().hasHeightForWidth());
        pushButton[i]->setSizePolicy(sizePolicy);
        gridLayout->addWidget(pushButton[i], i / 3, i % 3, 1, 1);
    }
    retranslateUI();

    QMetaObject::connectSlotsByName(this);
}

void TicTacToe::retranslateUI()
{
    setWindowTitle(QApplication::translate("MagnificientNothing", "MMortaaaaal Combaaat!!!", 0, QApplication::UnicodeUTF8));

    for (int i = 0; i < (SIZE - 1); i++)
    {
        pushButton[i]->setText(QApplication::translate("MagnificientNothing", "", 0, QApplication::UnicodeUTF8));
    }
    pushButton[SIZE - 1]->setText(QApplication::translate("MagnificientNothing", "Reset", 0, QApplication::UnicodeUTF8));
}

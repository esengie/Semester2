#include "ticTacToe.h"
#include <QMessageBox>

void TicTacToe::work()
{
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("MagnificientNothing"));

    resize(180, 180);

    typer = true;

    gridWidget = new QWidget(this);
    //gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
    gridWidget->setGeometry(QRect(0, 0, 180, 180));
    gridLayout = new QGridLayout(gridWidget);
    gridLayout->setSpacing(1);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);

    for (int i = 0; i < SIZE; i++)
    {
        control[i] = 0;
        pushButton[i] = new QPushButton(gridWidget);
        pushButton[i]->setObjectName(QString("%1").arg(i));
        sizePolicy.setHeightForWidth(pushButton[i]->sizePolicy().hasHeightForWidth());
        pushButton[i]->setSizePolicy(sizePolicy);
        pushButton[i]->setIcon(Cheng);
        pushButton[i]->setIconSize(QSize(50,50));
        //pushButton[i]->

        connect(pushButton[i], SIGNAL(clicked()), &mapper, SLOT(map()));
        connect(this, SIGNAL(check()), this, SLOT(on_check));
        mapper.setMapping(pushButton[i], i);
        gridLayout->addWidget(pushButton[i], i / 3, i % 3, 1, 1);
    }
    connect(&mapper, SIGNAL(mapped(int)), this, SLOT(procede(int)));
    connect(this, SIGNAL(check()), this, SLOT(on_check()));
    connect(this, SIGNAL(win(int)), this, SLOT(on_win(int)));
    connect(this, SIGNAL(reboot()), this, SLOT(on_reboot()));

    setWindowTitle(QApplication::translate("MagnificientNothing", "MMortaaaaal Combaaat!!!", 0, QApplication::UnicodeUTF8));

}

void TicTacToe::procede(int i)
{
    if (!control[i])
    {
        if (typer)
        {
            pushButton[i]->setIcon(Xim);
            typer = false;
            control[i] = 1;
        }
        else
        {
            pushButton[i]->setIcon(Yim);
            typer = true;
            control[i] = -1;
        }
        pushButton[i]->setIconSize(QSize(50,50));
        emit(check());
    }
}

void TicTacToe::on_check()
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (control[i])
            counter++;
    }
    if (counter == 9)
    {
        emit (win(0));
        exit;
    }
    int checky[8];
    for (int i = 0; i < 8; i++)
    {
        checky[i] = 0;
    }
    for (int j = 0; j < 3; j++)
        for (int i = j; i < SIZE; i+=3)
        {
            checky[j] += control[i];
        }
    for (int i = 0; i < SIZE; i++)
    {
        checky[3 + i / 3] += control[i];
    }
    checky[6] = control[0] + control[4] + control[8];
    checky[7] = control[2] + control[4] + control[6];
    for(int i = 0; i < 8; i++)
    {
        if (checky[i] > 2)
        {
            emit(win(1));
            break;
        }
        if (checky[i] < -2)
        {
            emit(win (-1));
            break;
        }
    }
}

void TicTacToe::on_win(int k)
{
    QMessageBox message;

    message.setWindowTitle("garble!");

    if (k)
    {
        if (k > 0)
        message.setText("Cross guy won");
        else
            message.setText("Circle guy won");
    }
    if (!k)
        message.setText("A tie!");
    message.setInformativeText("Would you like to start a new game?");
    QPushButton* newGame = message.addButton("New Game", QMessageBox::ActionRole);
    QPushButton* end = message.addButton("Close", QMessageBox::ActionRole);
    message.exec();
    if (message.clickedButton() == newGame)
                    emit(reboot());
    else if (message.clickedButton() == end)
                    close();

}

void TicTacToe::on_reboot()
{
    for (int i = 0; i < SIZE; i++)
    {
        control[i] = 0;
        pushButton[i]->setIcon(Cheng);
        pushButton[i]->setIconSize(QSize(50,50));
    }
    //typer = true;
}

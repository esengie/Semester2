#include "ticTacToe.h"
#include <QMessageBox>

void TicTacToe::work()
{
    if (objectName().isEmpty())
        setObjectName(QString::fromUtf8("MagnificientNothing"));
    int total = SIZE * SIZE;
    resize(SIZE * 52 + 2, SIZE * 52 + 2);

    typer = true;

    gridWidget = new QWidget(this);
    gridWidget->setGeometry(QRect(0, 0, SIZE * 52 + 2, SIZE * 52 + 2));
    gridLayout = new QGridLayout(gridWidget);
    gridLayout->setSpacing(2);
    gridLayout->setContentsMargins(0,0,0,0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

    for (int i = 0; i < total; i++)
    {
        control[i] = 0;
        pushButton[i] = new QPushButton(gridWidget);
        pushButton[i]->setObjectName(QString("%1").arg(i));
        pushButton[i]->setIcon(Cheng);
        pushButton[i]->setIconSize(icon_s);

        connect(pushButton[i], SIGNAL(clicked()), &mapper, SLOT(map()));
        connect(this, SIGNAL(check()), this, SLOT(on_check));
        mapper.setMapping(pushButton[i], i);
        gridLayout->addWidget(pushButton[i], i / SIZE, i % SIZE, 1, 1);
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
        emit(check());
    }
}

void TicTacToe::on_check()
{
    int whole_checks = SIZE * 2 + 2;
    int checky[whole_checks];
    for (int i = 0; i < whole_checks; i++)
    {
        checky[i] = 0;
    }
    for (int j = 0; j < SIZE; j++)
        for (int i = j; i < SIZE*SIZE; i+=SIZE)
        {
            checky[j] += control[i];
        }
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        checky[SIZE + i / SIZE] += control[i];
    }
    int main_d = whole_checks - 2;
    int antid = whole_checks - 1;
    int j = 0;
    for (int i = 0; i < SIZE; i++)
    {
        checky[main_d] += control[i * SIZE + j];
        checky[antid] += control[i * SIZE + (SIZE - 1) - j];
        j++;
    }
    for(int i = 0; i < whole_checks; i++)
    {
        if (checky[i] > SIZE - 1)
        {
            emit(win(1));
            exit;
        }
        if (checky[i] < -SIZE + 1)
        {
            emit(win (-1));
            exit;
        }
    }
    int counter = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        if (control[i])
            counter++;
    }
    if (counter == SIZE * SIZE)
    {
        emit (win(0));
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
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        control[i] = 0;
        pushButton[i]->setIcon(Cheng);
    }
    //typer = true;
}
TicTacToe::~TicTacToe()
{
    delete gridWidget;
    delete gridLayout;
    for (int i = 0; i < SIZE*SIZE; i++)
    {
       delete pushButton[i];
    }
}

#pragma once

//#include "button.h"
#include <QtGui/QWidget>
#include <QSignalMapper>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>
#include <QString>
#include <QVector>

/*
namespace TicciTacci {
    class TicTacToe;
}*/

class TicTacToe : public QWidget
{
    Q_OBJECT
    static const int SIZE = 5;
    bool typer;
public:
    explicit TicTacToe(QWidget *parent = 0): QWidget(parent), pushButton(SIZE*SIZE), control(SIZE*SIZE),
        Cheng("empty.png"), Xim("X.png"), Yim("O.png"), icon_s(10 + 20 * (SIZE - 1), 10 + 20 * (SIZE - 1)) { work(); }
    ~TicTacToe();
signals:
    void win(int);
    void reboot();
    void check();
protected slots:
    void procede(int);
    void on_win(int);
    void on_reboot();
    void on_check();
private:
    void work();
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QVector<QPushButton*> pushButton;
    QVector<int> control;
    QSignalMapper mapper;
    QIcon Cheng;           // i decided to give them korean names
    QIcon Xim;             // ...god i hate cheng!
    QIcon Yim;
    QSize icon_s;

};


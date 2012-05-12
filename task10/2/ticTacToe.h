#pragma once

#include <QtGui/QWidget>
#include <QSignalMapper>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QString>
/*
namespace TicciTacci {
    class TicTacToe;
}*/

class TicTacToe : public QWidget
{
    Q_OBJECT
    static const int SIZE = 10;
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QPushButton * pushButton[SIZE];

    explicit TicTacToe(QWidget *parent = 0): QWidget(parent) { setupUI(); }
    void setupUI();
    void retranslateUI();

//private:

};


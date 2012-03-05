#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>

namespace Ui {
    class Slider;
}

class Slider : public QWidget
{
    Q_OBJECT

public:
    explicit Slider(QWidget *parent = 0);
    ~Slider();

private:
    Ui::Slider *ui;
public slots:

};

#endif // SLIDER_H

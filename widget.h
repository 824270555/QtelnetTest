#ifndef WIDGET_H
#define WIDGET_H

#include "qttelnet.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QtTelnet *myTelnet;

private:
    Ui::Widget *ui;
    QString stripCR(const QString &msg);



public slots:
    void telnetMessage(const QString &msg);
    void lineReturnPressed();
};

#endif // WIDGET_H

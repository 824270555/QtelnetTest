#include "widget.h"
#include "ui_widget.h"
#include <QScrollBar>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTelnet = new QtTelnet;


    connect(ui->lineEdit, SIGNAL(returnPressed()),
            this, SLOT(lineReturnPressed()));
    connect(myTelnet, SIGNAL(message(const QString &)), this, SLOT(telnetMessage(const QString &)));
    connect(myTelnet, SIGNAL(loginRequired()), this, SLOT(telnetLoginRequired()));
//    connect(myTelnet, SIGNAL(loginFailed()), this, SLOT(telnetLoginFailed()));
//    connect(myTelnet, SIGNAL(loggedOut()), this, SLOT(telnetLoggedOut()));
//    connect(myTelnet, SIGNAL(loggedIn()),this, SLOT(telnetLoggedIn()));
//    connect(myTelnet, SIGNAL(connectionError(QAbstractSocket::SocketError)), this, SLOT(telnetConnectionError(QAbstractSocket::SocketError)));

        myTelnet->connectToHost("localhost");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::telnetMessage(const QString &msg)
{
    ui->textEdit->append(stripCR(msg));
    QScrollBar *s = ui->textEdit->verticalScrollBar();
    s->setValue(s->maximum());
    //qDebug() << msg;
}

QString Widget::stripCR(const QString &msg)
{
    QString nmsg(msg);
    nmsg.remove('\r');
    nmsg.remove(QRegExp("\033\\[[0-9;]*[A-Za-z]")); // Also remove terminal control codes
    return nmsg;
}

void Widget::lineReturnPressed()
{
    myTelnet->sendData(ui->lineEdit->text()+QString("\r\n"));
    ui->lineEdit->clear();
}

//void telnetLoginRequired()
//{
//    LoginDialog ld(this);
//    if (ld.exec() == LoginDialog::Accepted)
//        t->login(ld.login(), ld.password());
//    else
//        t->logout();
//}

//void telnetLoginFailed()
//{
//    status->setText("Login failed");
//}
//void telnetLoggedOut()
//{
//    lineEdit->setEnabled(false);
//    status->setText("Logged out");
//}
//void telnetLoggedIn()
//{
//    lineEdit->setEnabled(true);
//    status->setText("Logged in");
//}
//void telnetConnectionError(QAbstractSocket::SocketError error)
//{
//    status->setText(QString("Connection error: %1").arg(error));
//}

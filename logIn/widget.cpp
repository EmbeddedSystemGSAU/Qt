#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setStyleSheet("background-color:lightblue;");
    ui->setupUi(this);
    this->Login = new login;
    this->Sign = new sign;
    Login->setWindowTitle("登录");
    Sign->setWindowTitle("注册");


    connect(Login, &login::show_sign_signal,this,&Widget::signal_showsign);
    connect(Sign, &sign::show_login_signa, this, &Widget::signal_showlogin);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    this->hide();

    Login->show();
}

void Widget::on_pushButton_2_clicked()
{
    this->hide();
    //this->setStyleSheet("border: 2px solid black;");

    Sign->show();
}

void Widget::signal_showsign()
{
    this->Sign->show();
}

void Widget::signal_showlogin()
{
    this->Login->show();
}

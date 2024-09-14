#include "sign.h"
#include "ui_sign.h"
#include "widget.h"
#include <QFile>
#include <QDebug>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>
#include <QThread>
sign::sign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:lightblue;");
}

sign::~sign()
{
    delete ui;
}

void sign::on_pushButton_2_clicked()
{
    this->hide();
    emit show_login_signa(10);
}

void sign::on_pushButton_clicked()
{
    signID = ui->lineEdit->text();
    signPassword = ui->lineEdit_2->text();
    signMailbox = ui->lineEdit_3->text();

    QFile file("text.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        qDebug()<<"无法打开文件";
        return;
    }

    QTextStream out(&file);
    if(!signID.isEmpty()&&!signPassword.isEmpty()&&!signMailbox.isEmpty())
    {
        out<<"账号："+signID<<endl;
        QThread::msleep(20);
        out<<"密码："+signPassword<<endl;
        QThread::msleep(20);
        out<<"邮箱："+signMailbox<<endl;
        QThread::msleep(20);

        QMessageBox::information(this,"提示","注册成功，请返回登录");

    }
    else
    {
        qDebug()<<"无数据";
    }


    file.close();
    qDebug()<<"数据写入成功";
}

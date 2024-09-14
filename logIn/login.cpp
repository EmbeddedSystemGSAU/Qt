#include "login.h"
#include "ui_login.h"
#include "widget.h"
#include <QDebug>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:lightblue;");


}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    this->hide();
    emit show_sign_signal(10);
}

void login::on_pushButton_clicked()
{
    QFile file("text.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"无法打开文件";
        return;
    }
    else
    {
        qDebug()<<"文件打开成功";
    }

    loginID = ui->lineEdit->text();
    loginPassword = ui->lineEdit_2->text();

    QTextStream in(&file);
    QString st;
    int accountHAN = 0;         //表示无该账号
    while(!in.atEnd())
    {
        st = in.readLine();
        if(("账号："+loginID)==st)
        {
            accountHAN = 1;
            st = in.readLine();
            if(("密码："+loginPassword)==st)
            {
                qDebug()<<"密码正确";
                this->hide();
                QCoreApplication::quit();
                break;
            }
            else
            {
                qDebug()<<"密码错误";
                QMessageBox::warning(this,"警告","请输入正确密码");
                break;
            }
        }
        else
        {
            qDebug()<<"无账号";
            accountHAN = 0;
        }
    }
    if(!accountHAN)
        QMessageBox::warning(this,"警告","未找到账号信息，请重新输入或注册");
    file.close();
}

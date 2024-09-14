#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    QString loginID;
    QString loginPassword;
    ~login();
signals:
    void show_sign_signal(int a);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    //void emit_signal();


    void on_pushButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H

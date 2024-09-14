#ifndef SIGN_H
#define SIGN_H

#include <QWidget>
#include <QString>
namespace Ui {
class sign;
}

class sign : public QWidget
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    QString signID;
    QString signPassword;
    QString signMailbox;
    ~sign();
signals:
    void show_login_signa(int a);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::sign *ui;
};

#endif // SIGN_H

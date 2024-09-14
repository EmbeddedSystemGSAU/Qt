#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "login.h"
#include "sign.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    login *Login;
    sign *Sign;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void  signal_showsign();
    void  signal_showlogin();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

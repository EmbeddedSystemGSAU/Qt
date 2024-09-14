#include "widget.h"

#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("主页面");
    w.setFixedSize(800,600);
    w.show();
    return a.exec();
}

#include "widget.h"
#include "ui_widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.draw();

    return a.exec();
}

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "game.h"
#include <QString>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    Game *game = new Game();
    void draw();        //显示

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    void keyPressEvent(QKeyEvent *event);       //获取输入并执行相应操作
};

#endif // WIDGET_H

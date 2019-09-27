#include "widget.h"
#include "ui_widget.h"
#include "game.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);    
    setWindowFlags(Qt::CustomizeWindowHint |
                   Qt::WindowCloseButtonHint |
                   Qt::WindowMinimizeButtonHint);
    game->initGame();
    this->setFocus();
}

Widget::~Widget()
{
    delete ui;
    delete game;
}

void Widget::draw()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <cols; j++)
        {
            int t=i*4+j+1;
            if(game->map[i][j]){
                switch (t) {
                case 1:
                    ui->label1->setText(QString::number(game->map[0][0]));
                    break;
                case 2:
                    ui->label2->setText(QString::number(game->map[0][1]));
                    break;
                case 3:
                    ui->label3->setText(QString::number(game->map[0][2]));
                    break;
                case 4:
                    ui->label4->setText(QString::number(game->map[0][3]));
                    break;
                case 5:
                    ui->label5->setText(QString::number(game->map[1][0]));
                    break;
                case 6:
                    ui->label6->setText(QString::number(game->map[1][1]));
                    break;
                case 7:
                    ui->label7->setText(QString::number(game->map[1][2]));
                    break;
                case 8:
                    ui->label8->setText(QString::number(game->map[1][3]));
                    break;
                case 9:
                    ui->label9->setText(QString::number(game->map[2][0]));
                    break;
                case 10:
                    ui->label10->setText(QString::number(game->map[2][1]));
                    break;
                case 11:
                    ui->label11->setText(QString::number(game->map[2][2]));
                    break;
                case 12:
                    ui->label12->setText(QString::number(game->map[2][3]));
                    break;
                case 13:
                    ui->label13->setText(QString::number(game->map[3][0]));
                    break;
                case 14:
                    ui->label14->setText(QString::number(game->map[3][1]));
                    break;
                case 15:
                    ui->label15->setText(QString::number(game->map[3][2]));
                    break;
                case 16:
                    ui->label16->setText(QString::number(game->map[3][3]));
                    break;
                }
            }
            else{
                switch (t) {
                case 1:
                    ui->label1->setText(" ");break;
                case 2:
                    ui->label2->setText(" ");break;
                case 3:
                    ui->label3->setText(" ");break;
                case 4:
                    ui->label4->setText(" ");break;
                case 5:
                    ui->label5->setText(" ");break;
                case 6:
                    ui->label6->setText(" ");break;
                case 7:
                    ui->label7->setText(" ");break;
                case 8:
                    ui->label8->setText(" ");break;
                case 9:
                    ui->label9->setText(" ");break;
                case 10:
                    ui->label10->setText(" ");break;
                case 11:
                    ui->label11->setText(" ");break;
                case 12:
                    ui->label12->setText(" ");break;
                case 13:
                    ui->label13->setText(" ");break;
                case 14:
                    ui->label14->setText(" ");break;
                case 15:
                    ui->label15->setText(" ");break;
                case 16:
                    ui->label16->setText(" ");break;
                }
            }
        }
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    show();
    //根据按键执行相应的函数
    if(event->key()==Qt::Key_Up)
    {
        game->up();
        this->draw();
    }
    if(event->key()==Qt::Key_Left)
    {
        game->left();
        this->draw();
    }
    if(event->key()==Qt::Key_Right)
    {
        game->right();
        this->draw();
    }
    if(event->key()==Qt::Key_Down)
    {
        game->down();
        this->draw();
    }
    if(game->lose())     //失败提示
    {
        QMessageBox::about(nullptr, "Lose", "You lose!");
    }
    if(game->win())      //胜利提示
    {
        QMessageBox::about(nullptr, "Win", "You win!");
    }
    ui->label_2->setText(QString::number(game->score));
}

void Widget::on_pushButton_clicked()
{
    game->initGame();
    this->draw();
    this->setFocus();
    ui->label_2->setText(QString::number(0));
}

#ifndef GAME_H
#define GAME_H

const int rows=4;
const int cols=4;

class Game
{
public:  

    int score = 0;//初始分数
    bool ADD = true;//能否添加数字
    int map[rows][cols] = {};

    void initGame();//初始化游戏

    bool win();//判断是否赢了
    bool lose();//判断是否输了
    void add();//添加数字

    void up();//上下左右按键事件
    void down();
    void right();
    void left();

};

#endif // GAME_H

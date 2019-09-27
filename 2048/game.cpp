#include "game.h"
#include <QRandomGenerator>         //随机数头文件

void Game::initGame()       //初始化游戏
{
    this->score = 0;//初始分数
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            map[i][j] =0;
        }
    }
    this->add();
    this->add();
}

void Game::add()        //添加一个新数字
{
    int choice[] = { 4, 2, 4, 2, 4, 2, 2, 2 };//可以调节2和4出现的频率
    int temp = (QRandomGenerator::global()->bounded(256) % static_cast<int>((sizeof(choice)/sizeof(choice[0]))));
    int p1 = QRandomGenerator::global()->bounded(256) % 4;
    int p2 = QRandomGenerator::global()->bounded(256) % 4;
    while (this->map[p1][p2] != 0)  //位置已有数字，重新选取
    {
        p1 = QRandomGenerator::global()->bounded(256) % 4;
        p2 = QRandomGenerator::global()->bounded(256) % 4;
    }
    map[p1][p2] = choice[temp];

    for (size_t i = 0; i <rows; i++)       //判断能否再添加数字
    {
        for (size_t j = 0; j <cols; j++)
        {
            if(map[i][j]==0){
                ADD = true;
                return ;
            }
        }
    }
    ADD=false;
}

bool Game::lose()           //判断游戏是否失败
{
    //map数组出现0，表示还未结束
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j <cols; j++)
        {
            if (map[i][j] == 0)
                return false;
        }
    }
    //横竖相邻元素相等,表示未结束
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols - 1; j++)
        {
            if (map[i][j]== map[i][j+1]&& map[i][j]!=0)
            {
                return false;
            }
            if (map[j][i]== map[j+1][i]&& map[j][i]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Game::win()        //判断游戏是否胜利
{
    for (size_t i = 0; i <rows; i++)
    {
        for (int j = 0; j <cols; j++)
        {
            //出现2048，即为赢
            if (this->map[i][j]==2048)
            {
                return true;
            }

        }
    }
    return false;
}

void Game::up()     //上移
{
    for(size_t j=0; j<cols; j++)
    {
        int t[rows], cnt=0;     //临时存储及索引
        //取出所有非零元素
        for(size_t i=0; i<rows; i++){
            if(map[i][j])
                t[cnt++] = map[i][j];
        }
        int n = 0;
        //合并所有非零元素
        for(int k=0; k<cnt-1; k++)
        {
            if(t[k]==t[k+1])
            {
                ADD=true;
                t[k] *= 2;
                score += t[k];
                t[k+1] = 0;
            }
        }
        //将合并后的非零元素填入map中
        for(int k=0; k<cnt; k++)
        {
            if(t[k])
                map[n++][j] = t[k];
        }
        //尾部补零
        for(; n<rows; n++)
        {
            map[n][j] = 0;
        }
    }
    //添加数字
    if(ADD){
        add();
    }
}

void Game::down()       //下移
{
    for(size_t j=0; j<cols; j++)
    {
        int t[rows], cnt=0;     //临时存储及索引
        //取出所有非零元素
        for(int i=rows-1; i>=0; i--){
            if(map[i][j])
                t[cnt++] = map[i][j];
        }
        int n = rows-1;
        //合并所有非零元素
        for(int k=0; k<cnt-1; k++)
        {
            if(t[k]==t[k+1])
            {
                ADD=true;
                t[k] *= 2;
                score += t[k];
                t[k+1] = 0;
            }
        }
        //将合并后的非零元素填入map中
        for(int k=0; k<cnt; k++)
        {
            if(t[k])
                map[n--][j] = t[k];
        }
        //尾部补零
        for(; n>=0; n--)
        {
            map[n][j] = 0;
        }
    }
    //添加数字
    if(ADD){
        add();
    }
}

void Game::left()           //左移
{
    for(size_t j=0; j<rows; j++)
    {
        int t[cols], cnt=0;     //临时存储及索引
        //取出所有非零元素
        for(size_t i=0; i<cols; i++){
            if(map[j][i])
                t[cnt++] = map[j][i];
        }
        int n = 0;
        //合并所有非零元素
        for(int k=0; k<cnt-1; k++)
        {
            if(t[k]==t[k+1])
            {
                ADD=true;
                t[k] *= 2;
                score += t[k];
                t[k+1] = 0;
            }
        }
        //将合并后的非零元素填入map中
        for(int k=0; k<cnt; k++)
        {
            if(t[k])
                map[j][n++] = t[k];
        }
        //尾部补零
        for(; n<cols; n++)
        {
            map[j][n] = 0;
        }
    }
    //添加数字
    if(ADD){
        add();
    }
}

void Game::right()          //右移
{
    for(size_t j=0; j<rows; j++)
    {
        int t[cols], cnt=0;     //临时存储及索引
        //取出所有非零元素
        for(int i=cols-1; i>=0; i--){
            if(map[j][i])
                t[cnt++] = map[j][i];
        }
        int n = cols-1;
        //合并所有非零元素
        for(int k=0; k<cnt-1; k++)
        {
            if(t[k]==t[k+1])
            {
                ADD=true;
                t[k] *= 2;
                score += t[k];
                t[k+1] = 0;
            }
        }
        //将合并后的非零元素填入map中
        for(int k=0; k<cnt; k++)
        {
            if(t[k])
                map[j][n--] = t[k];
        }
        //尾部补零
        for(; n>=0; n--)
        {
            map[j][n] = 0;
        }
    }
    //添加数字
    if(ADD){
        add();
    }
}



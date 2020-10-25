#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
//#pragma warning(disable:4996)   //vs报错可能需要用到这个
int main(int argc, char** acgv)
{
    int cols, size, fps, len, X = 0, Y = 0, i, * p = 0, * map;
    char move = 'D', buf = 0, * print, * p_c;
    //cols: 地图尺寸; size: 地图大小; fps: 帧数;
    //len: 蛇的长度; X, Y: 头的坐标; i, p: 临时变量
    //map: 地图, 每个元素的映射, -1为食物 0为空地 大于0为蛇(值为存活回合)
    //move: 动作; buf: 输入缓冲; print: 输出缓冲; p_c: char指针(临时变量)

    cols = argc > 1 ? atoi(acgv[1]) : 10;   //地图尺寸, 默认为10
    fps = argc > 2 ? atoi(acgv[2]) : 10;    //游戏帧数, 默认为10
    len = argc > 3 ? atoi(acgv[3]) : 3;     //蛇的长度, 默认为3
    if (cols * fps * len == 0)return 1;     //判断参数是否存在0(存在则直接退出)
    //获取命令行参数(如果有的话), 设置全局变量

    fps = 1000 / fps, size = cols * cols;
    map = calloc(size, 4), print = calloc((size + cols) * 2 + 1, 1);
    while (map[i = rand() % size]);
    //将帧数转换相应的延迟, size设置为对应大小
    //寻找空地, 分配内存, print要包含边界, 换行符还有'\0'需要额外的空间

    //初始化随机数种子, 设置食物; 输入不为Esc键则继续执行; 延迟
    for (srand((unsigned)map), map[i] = -1; buf - 27; _sleep(fps))
    {
        if (_kbhit() && (buf = _getch() & 95)) //检测输入 -> 获取输入, 小写转大写
            switch (buf)
            {
            case 'A':if (move != 'D')move = 'A'; break; //如果与原动作不冲突
            case 'D':if (move != 'A')move = 'D'; break; //则覆盖原动作
            case 'S':if (move != 'W')move = 'S'; break;
            case 'W':if (move != 'S')move = 'W'; break;
            }
        //输入

        switch (move)
        {
        case 'A':p = &X, *p -= 1; break;    //p指向对应轴, 并更新坐标
        case 'D':p = &X, *p += 1; break;
        case 'S':p = &Y, *p += 1; break;    //因为Y轴向下为正, 所以这里是加1
        case 'W':p = &Y, *p -= 1; break;
        }
        *p = (*p + cols) % cols;    //如果越界, 则移动至另一端
        //更新坐标 p指向坐标轴

        p = map + X + Y * cols; //p指向蛇头对应的地图元素
        if (*p > 1)break;       //如果大于1(撞到蛇), 游戏结束 (ps: 1为蛇尾)
        if (*p == -1)           //如果为食物
        {
            while (map[i = rand() % size]); //寻找空地
            map[i] = -1, len += 1;          //设置食物, 蛇长+1
        }
        else for (i = 0; i < size; ++i) //空地
            if (map[i] > 0)map[i] -= 1; //遍历地图, 所有蛇的值-1 (去掉蛇尾)
        //状态判断 p指向地图元素, i为空地下标

        for (*p = len, p_c = print, i = 0; i < size;)   //蛇头赋值, 遍历地图
        {
            if (map[i] == 0)p_c[0] = p_c[1] = ' ';          //如果为空地
            else if (map[i] > 0)p_c[0] = '(', p_c[1] = ')'; //如果为蛇
            else p_c[0] = p_c[1] = '0';                     //空地
            p_c += 2, i += 1;
            if (i % cols == 0)                              //如果到下一行的元素
                p_c[0] = '#', p_c[1] = '\n', p_c += 2;      //边界和换行
        }
        system("cls"), printf(print);                       //清屏, 打印
        //打印输出 p_c指向print(遍历), i为循环变量(遍历)
    }
    printf("\nGame over!\n"), free(map), free(print);   //结束, 释放内存
}

//创建于2020.10.25, 以下为@NGBPTKM62的补充说明
/******************************************************************************
54行贪吃蛇（不含注释，空行）
拆解了复杂的表达式，有不错的可读性，以及注释

看了之前的std版本，写的很不错，感觉有一定的参考价值，也不至于标成old吧。。按照UP最近写
的14行tiny版本尝试自己重新写了一个，写的还可以吧qwq

old_std版本中，减少调用系统函数（输出）的次数，提高性能来减少闪烁，这个思路非常好，有
明显的改善，地图尺寸越大，效果越突出。可惜修改某些参数却极为困难，特别是地图尺寸。。像
tiny版本那样就很棒，还可以继续发展，用命令行来指定大小（这个是在screen版本里学到的操作
真的学到了），就不用修改地图大小时重新编译了。

不得不说，UP写的代码非常有意思，视频也做的非常棒，能学到不少东西，希望UP能一直做下去
******************************************************************************/

#include<stdlib.h>
#include<conio.h>
#pragma warning(disable:4996)
int main() {
    system("mode con: cols=60 lines=31");
    int hX = 7, hY = 7, num = 4, map[900] = { 0 }, i = 0;
    char c = 'd', cl = 'd';
    srand((unsigned)&map);
    for (map[rand() % 900] = -1; system("cls"), 1; _sleep(50)) {
        if (_kbhit())cl = _getch();
        if ((cl == 'a'&&c != 'd') || (cl == 'd'&&c != 'a') || (cl == 'w'&&c != 's') || (cl == 's'&&c != 'w'))c = cl;
        if (c == 'a'&&--hX < 0)break;
        else if (c == 'd'&&++hX == 30)break;
        else if (c == 'w'&&--hY < 0)break;
        else if (c == 's'&&++hY == 30)break;
        if (map[hY * 30 + hX] > 1)break;
        if (map[hY * 30 + hX] < 0 && num++)map[rand() % 900] = -1;
        else for (int i = 0; i < 900; i++)if (map[i] > 0)map[i] -= 1;
        for (map[hY * 30 + hX] = num + 1; i < 900 || (i = 0); i++) {
            if (!map[i])cputs("  ");
            else if (map[i] > 0)cputs("()");
            else cputs("00");
        }
    }
}

/*
25行贪吃蛇, 1024字符, 实现了简单的功能;
adsw移动(不支持大写), 吃到食物成长, 吃到自己身体时或撞墙时游戏结束;
可自定义蛇头位置(hX, hY), 蛇长(len), 初始方向(c);
远古时期写的代码了, 看看就行了...
在当时, 从100+行, 70+, 50+, 40+, 30+,到25行, 已经很不错了
然而现在都14行了...
当时还是和一个朋友互相打脸, 比谁写的更少...
有点怀念当时的情景, 能遇到和自己代码风格极其相似的朋友真的太好了...
最精彩的部分也就是这个数据结构了, 最后能打赢都靠的这个
本来想上传朋友的代码, 然而他不让, 我也没有备份, 就没办法了...

2020.10.17 改用空格缩进(不然字符少很多, 和前面的统一标准)
于2019.12.15上传, 2020.10.2补充说明
*/
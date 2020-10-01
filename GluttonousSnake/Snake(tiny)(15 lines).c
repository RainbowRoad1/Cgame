#include <stdlib.h>
#include <conio.h>
int main() {
    int map[900] = {0}, z[3] = {0}, len = 4, c = 'D', C, i, *p, a;      //地图,头坐标(x,y,x+W*y),长度,动作,动作缓冲,循环变量,指针,变量
    srand((int)(p = (int *)malloc(!system("mode con:cols=60 lines=30"))));  //初始化随机数种子,使用malloc产生随机数(地址),修改窗口大小
    for (free(p), map[rand() % 900] = -1; a = 1; _sleep(100)) {         //释放,生成种子;a变量复位;延迟
        if (_kbhit()) C = _getch() & 95, C - 65 && C - 68 &&            //如有输入,获取,大小转小写,判断动作是否冲突
            C - 83 && C - 87 || ((C ^ c) & 20) - 4 && (c = C);          //(这里细节很多,可以慢慢理解)
        p = z + !!(c & 16), *p += c / 6 & 1 ? 1 : -1, *p = (*p + 30) % 30;  //更新头坐标,越界判断(越界从另一端出现)
        if (map[z[2] = *z + z[1] * 30] < 0 || map[z[2]] > 1 && (exit(0), 0))//判断新的头坐标
            for (; map[i = rand() % 900] || (map[i] = -1, ++len, a = 0););  //生成食物.增加蛇长,a=0(保留蛇尾)
        for (system("cls"), map[z[2]] = len + 1, i = 0; i < 900; i++)       //清屏, 头坐标赋值,循环打印地图
            _cputs(map[i] > 0 && (map[i] -= a) ? "()" : map[i] ? "00" : "  ");//打印
    }
}
/*
15行贪吃蛇, 779字符, 实现了简单的功能;
ADSW移动, 吃到食物成长, 可穿墙, 吃到自己身体时游戏结束;
可自定义蛇头位置(z[0], z[1]), 蛇长(len), 初始方向(c);
在18行的版本上加以改进, 避免了malloc()返回值被忽略的问题, 以及可穿墙;
我不记得自己有写过这么详细的注释诶...(雾)
此处使用gcc编译通过, vs需要屏蔽4996号错误, 加上下面一行代码
#pragma warning(disable:4996)
于2020.6.13上传, 2020.10.1补充说明

下面是之前的说明:

偷偷更新~应该没人发现吧(除了群里的)(2020.6.13)
使用gcc编译通过(MinGW)(gcc version 8.2.0)
编译有警告,但不影响
还是不懂为什么用_sleep()会警告...用windows.h下的Sleep()就不会警告了
(其实18行贪吃蛇windows.h可以换成stdlib.h的)
*/
/*
去光标&闪烁方法(在Maze使用过的技巧)： 
1行: 把 stdlib.h 改成 windows.h 
12行: 把 system("cls") 去掉
5~6行之间插入：
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) { 25, 0 });
11~12行之间插入：
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { 0, 0 });
*/

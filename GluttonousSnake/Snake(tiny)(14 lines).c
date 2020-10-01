#include <stdlib.h>
#include <conio.h>
int main() {
    int W = 20, S = W * W, *m, z[2] = {0}, l = 3, i, c = 'D', C, *p, f;
    for (srand(m = calloc(S, 4)), C = m[1] = -1; C - 27; _sleep(100)) {
        if (_kbhit())C = _getch() & 95, C - 65 && C - 68 &&
            C - 83 && C - 87 || (C ^ c) & 20 ^ 4 && (c = C);
        p = z + !!(c & 2), *p += c / 3 & 2, *p = (--*p + W) % W;
        f = !system("cls"), *(p = m + *z + z[1] * W) > 0 && (C = 27);
        for (; *p && (m[i = rand() % S] || (--m[i], ++l, --f)););
        for (i = 0, *p = l; i < S; ++i % W || _cputs("|\n"))
            _cputs(m[i] > 0 ? m[i] -= f, "()" : m[i] ? "00" : "  ");
    }
}

/*
14行贪吃蛇, 668字符, 实现了简单的功能;
ADSW移动, 吃到食物成长, 可穿墙, 吃到自己身体或按下Esc键时游戏结束;
可自定义蛇头位置(z[0], z[1]), 蛇长(l), 初始方向(c), 地图尺寸(W);
在15行的版本上加以改进, 增加了Esc键退出, 更方便的自定义地图大小;
注意: 初次食物生成是固定位置, 默认情况下会在第一轮循环后重新生成
(除非你手速特别快, 或者修改了默认参数, 一般都不用在意这点细节)
于2020.7.4上传, 2020.10.1补充说明

下面是之前的说明:

修改了一点点代码, 比之前少了许多代码...
VS出现4996号错误加上此代码可解决
#pragma warning(disable:4996)
2020.9.30

使用gcc编译通过(MinGW)(gcc version 8.2.0)
在15行的基础上更改了一些细节，以及
修改地图大小更方便了，Esc键退出
*/
/*
去光标&闪烁方法(在Maze使用过的技巧)： 
1行: 把 stdlib.h 改成 windows.h 
9行: 把 system("cls") 去掉
4~5行之间插入：
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) { 25, 0 });
10~11行之间插入：
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { 0, 0 });
*/

#include <windows.h>
#include <conio.h>
int main() {
    int W = 20, S = W * W, * m, z[2] = { 0 }, l = 3, i, c = 'D', C, * p, f;
    SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO){25});
    for (srand(m = calloc(S, 4)), C = m[1] = -1; C - 27; Sleep(100)) {
        if (_kbhit())C = _getch() & 95, C - 65 && C - 68 &&
            C - 83 && C - 87 || (C ^ c) & 20 ^ 4 && (c = C);
        p = z + !!(c & 2), * p += c / 3 & 2, * p = (-- * p + W) % W;
        f = 1, * (p = m + *z + z[1] * W) > 0 && (C = 27);
        for (; *p && (m[i = rand() % S] || (--m[i], ++l, --f)););
        SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD){0});
        for (i = 0, *p = l; i < S; _cputs("  "), ++i % W || _cputs("\n"))
            SetConsoleTextAttribute(GetStdHandle((DWORD)-11),
                m[i] > 0 ? m[i] -= f, 192 : m[i] ? 160 : 240);
    }
}

/*
彩色版贪吃蛇, 888字符, 给界面增加一些颜色;
ADSW移动, 吃到食物成长, 可穿墙, 吃到自己身体或按下Esc键时游戏结束;
可自定义蛇头位置(z[0], z[1]), 蛇长(l), 初始方向(c), 地图尺寸(W);
注意: 初次食物生成是固定位置, 默认情况下会在第一轮循环后重新生成
(除非你手速特别快, 或者修改了默认参数, 一般都不用在意这点细节)
于2020.7.4上传, 2020.10.1补充说明

下面是之前的说明:

在14行贪吃蛇的基础上加以修改
界面比之前舒服了许多...
使用了部分c99特性
2020.9.30
*/
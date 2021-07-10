#include <conio.h>
#include <stdlib.h>
int S, W = 9, H = 9, B = 10, s, p = 0, c = 1, i, *m, *M, (*f)(int, int);
int edge(int x, int y) { return !(-~x % -~W && -~y % -~H); }
void tmp(int x, int y) { edge(x, y) || m[x += W * y] - 9 && ++m[x]; }
void dig(int v, int l) {
    for (l = edge(v, l) || M[v += W * l] || (++M[v], --s, m[v]) ? 0 : 9; l;)
        --l - 4 || --l, f(v % W + l % 3 - 1, v / W + l / 3 - 1);
}
void set(int x, int y) {
    for (f = tmp, srand(m); c < B || (f = dig, f(x, y), s += B, 0);)
        if (m[i = rand() % S] < 9 && 1 < (abs(x - i % W) | abs(y - i / W)))
            m[i] = 0, dig(i % W, i / W), m[i] = 9, --M[i], ++c;
}
int main() {
    f = set, s = S = W * H, m = calloc(S * 2, 4), M = m + S;
    for (; c - 27 && !system("cls"); c = B % s ? _getch() & 95 : 27) {
        c - 68 || ++p, c - 65 || --p, c - 83 || (p += W), c - 87 || (p -= W);
        p = (p + S) % S, c || (f(p % W, p / W), m[p] < 9 || (B = 0));
        for (i = 0; B || m[i] - 9 || ++M[i], i < S; ++i % W || _cputs("\n"))
            _cprintf("%c%c", " >"[p == i], " 12345678@*"[M[i] ? m[i] : 10]);
    }
    _cputs(B - s ? "Game over!" : "You win!"), _getch();
}

/*
24行扫雷, 1182字符, 实现了简单的功能;
ADSW移动光标, 空格挖开对应格子, 剩余格子等于雷的数量或挖到雷或按下Esc键时游戏结束;
可自定义地图尺寸(W, H), 雷的数量(B), 地图尺寸不要太小或太大
跟之前的版本完全是两种体验...
2021.7.10
    *调整代码: 格式化后完全一致
    *调整结构: 获胜时不再被getch()阻塞
2021.2.23
    *调整代码: 尽量与格式化后的代码一致
    *添加细节: 挖到雷后, 会显示所有的雷
    *优化算法: 第一次挖开的位置周围不会生成雷
2020.10.3
    结束不显示时间(不影响游戏主体), 行数-1
2020.7.4
    添加W, H, B变量, 方便测试以及拓展
2020.6.25
    上传
*/

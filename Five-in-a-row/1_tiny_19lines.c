#include <stdlib.h>
#include <conio.h>
int W = 13, S, *m, z = 0, c = 1, r = 2, i, j;
int sum(int v, int l){
    return (abs(v % W - (v + l) % W) - W + 1 && v + l >= 0 && v + l < S) && 
        m[v] == m[v + l] ? 1 + sum(v + l, l) : 0;
}
int main(){
    for (m = calloc(S = W * W, 4); r < 4 && c - 27; c = _getch() & 95){
        c - 68 || ++z, c - 65 || --z, c - 83 || (z += W), c - 87 || (z -= W);
        if (z = (z + S) % S, system("cls"), i = 2, !c && !m[z])
            for (m[z] = r ^= 3; j = i % 3 - 1 + i / 3 * W, i < 6; ++i)
                sum(z, j) + sum(z, -j) > 3 && (r ^= 3, i = r += 4);
        for (i = 0; i < S; ++i % W || _cprintf("%d\n", i / W))
            _cprintf("%c%c", " >"[i == z], " 0@"[m[i]]);
        for (i = 0; i < W; ++i)_cprintf(" %c", 97 + i);
        _cprintf(r & 1 ? "\nWhite" : "\nBlack"), r < 4 || _cputs(" win!");
    }
}

/*
adsw移动，空格下子，Esc退出，黑方先手，先达成五连的获胜
'@'是白棋,'O'是黑棋,'>'是光标, 可自定义棋盘尺寸(W)
大小可以自己改(3行的W)(固定长宽比1:1)
和上次的迷宫一样，感觉没什么很复杂的部分，界面和交互直接照搬扫雷

感谢某热心群友测试指出一处隐患和一处逻辑错误(2020.7.25更新)
真有群友测试是我万万没想到的...

2020.10.5优化部分代码

于2020.7.24上传
*/

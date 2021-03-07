#include <windows.h>
#include <conio.h>
#include <stdio.h>
int S, W = 9, H = 9, B = 10, s, p = 0, c = 1, i, *m, *M, (*f)(int, int), *O;
int edge(int x, int y) { return x < 0 || W <= x || y < 0 || H <= y; }
void tmp(int x, int y) { edge(x, y) || m[x += W * y] - 9 && ++m[x]; }
void dig(int v, int l) {
	for (l = edge(v, l) || M[v += W * l] || (++M[v], --s, m[v]) ? 0 : 9; l;)
		--l - 4 || --l, f(v % W + l % 3 - 1, v / W + l / 3 - 1);
}
void set(int x, int y) {
	for (f = tmp; c++ < B; m[i] = 0, dig(i % W, i / W), m[i] = 9, M[i]--)
		while (m[i = rand() % S] > 8 || (abs(x - i % W) | abs(y - i / W)) < 2);
	f = dig, s += B, dig(x, y);
}
int main(){
	f = set, s = S = W * H, m = calloc(S * 2, 4), O = GetStdHandle((DWORD)-11);
	SetConsoleCursorInfo(O, &(CONSOLE_CURSOR_INFO){1}), M = m + S, srand(m);
	for (; B % s; c = _getch() & 95, c - 83 || (p += W), c - 87 || (p -= W)) {
		SetConsoleCursorPosition(O, (COORD){0}), c - 68 || ++p, c - 65 || --p;
		p = (p + S) % S, c || (f(p % W, p / W), m[p] < 9 || (B = 0)), i = 0;
		for (c - 27 || (B = 0); c = B | m[i] < 9, i < S; ++i % W || puts(""))
			SetConsoleTextAttribute(O, (M[i] ? m[i] : 9) | (p - i ? 240 : 64)),
				c || ++M[i], printf(M[i] ? " %c" : "■", " 12345678@"[m[i]]);
	}
	_cputs(B ? "You win!" : "Game over!"), _getch();
}

/*
彩色版扫雷, 1308字符, 给界面增加一些颜色;
ADSW移动光标, 空格挖开对应格子, 剩余格子等于雷的数量或挖到雷或按下Esc键时游戏结束;
可自定义地图尺寸(W, H), 雷的数量(B), 地图尺寸不要太小或太大
又是一种全新的体验...

2021.3.7
	上传
*/

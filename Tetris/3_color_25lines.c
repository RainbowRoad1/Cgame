#include <windows.h>
#include <conio.h>
#define Get(C) for (C, i = n[T]; j = X + i % 4, k = Y + i / 4 % 4, i; i >>= 4)
int W = 10, H = 25, S, i, j, k, c, d = 0, X = 0, Y = 0, T = 0, *m, n[] = {
	51264, 12816, 21520, 21520, 25872, 34113, 21537, 38208, 25921, 38481,
	38484, 38209, 25922, 43345, 34388, 38160, 25920, 38177, 42580, 38993};
int move(int* v, int l) {
	Get (*v += l)(j < 0 || j >= W || k >= H || m[k * W + j]) && (c = 0);
	return c ? 1 : (*v -= l, v == &Y && (c = -1));
}
int main() {
	SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO){25});
	for (srand(m = calloc(S = W * H, 4)); c - 27; Sleep(50)) {
		Get(c = _kbhit() ? _getch() & 95 : 1) m[k * W + j] = 0;
		c ^ 87 || (i = T < 8 ? 1 : 3, move(&T, T & i ^ i ? 1 : -i));
		c ^ 65 && c ^ 68 || move(&X, c & 1 ? -1 : 1), c ^ 83 || move(&Y, 1);
		Get(--d || (d = 10, move(&Y, c = 1))) m[k * W + j] = T / 4 * 17 + 154;
		SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD){0});
		for (; i < S; _cputs("  "), ++i % W || _cputs("\n"))
			SetConsoleTextAttribute(GetStdHandle((DWORD)-11), m[i]);
		if (c == -1 && !(Y || (c = 27), T = rand() % 20, Y = X = 0))
			for (j = W, i = S - 1; j -= !!m[i], i; i-- % W || (j = W))
				for (j || (k = i += W); !j && (--k >= W); m[k] = m[k - W]);
	}
}

/*
彩色版俄罗斯方块, 1288字符, 给界面增加一些颜色;
AD移动, S下坠, W旋转, 某一行填满方块则消行, 当方块堆到顶层或按下Esc键时游戏结束;
可自定义地图尺寸(W, H)
和之前比几乎是截然不同的体验...

2020.11.13
	优化代码, 行数-1
2020.10.2
	补充说明
2020.9.19
	上传
*/

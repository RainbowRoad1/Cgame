#include <stdlib.h>
#include <conio.h>
#pragma warning(disable:4996)
#define Get(C) for (C, i = n[T]; j = X + i % 4, k = Y + i / 4 % 4, i; i >>= 4)
int W = 10, H = 25, S, i, j, k, c, d = 0, X = 0, Y = 0, T = 0, * m, n[28] = {
51264, 12816, 21520, 21520, 25872, 34113, 21537, 38208, 25921, 38481,
38484, 38209, 25922, 43345, 34388, 38160, 25920, 38177, 42580, 38993
};
int move(int* v, int l) {
	Get(*v += l) (j < 0 || j >= W || k >= H || m[k * W + j]) && (c = 0);
	return c ? 1 : (*v -= l, v == &Y && (c = -1));
}
int main() {
	for (srand(m = calloc(S = W * H, 4)); c - 27; _sleep(50), system("cls")) {
		Get(c = _kbhit() ? c = _getch() & 95 : 1) m[k * W + j] = 0;
		c ^ 87 || (i = T < 8 ? 1 : 3, move(&T, T & i^ i ? 1 : -i));
		c ^ 65 && c ^ 68 || move(&X, c & 1 ? -1 : 1), c ^ 83 || move(&Y, 1);
		Get(++d - 10 || (d = 0, c = 1, move(&Y, 1))) m[k * W + j] = 1;
		for (; i < S; ++i % W || _cputs("|\n"))_cputs(m[i] ? "[]" : "  ");
		if (c + 1 || Y < 1 && (c = 27) || (T = rand() % 19, Y = 0))continue;
		for (X = 0, j = W, i = S - 1; j -= m[i], i >= W; i-- % W || (j = W))
			for (k = i + W; !j && (--k >= W || !(i += W)); m[k] = m[k - W]);
	}
}
/*
修改了一点细节, 大概就这样了...
*把2行超过80字符的压缩了一下
*解决了移动与下落会冲突的问题
2020.9.19

写着写着就只有24行了？
既然能运行就先上传了
也许还需要再修改下...
2020.9.13
*/

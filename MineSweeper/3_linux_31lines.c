#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define OUT (x < 0 || W <= x || y < 0 || H <= y)
int W = 9, H = 9, B = 10, *m, *k, s, z, c = 1, i, j, (*f)(int, int);
void tmp(int x, int y) { OUT || m[x + W * y] - 16 && m[x + W * y]++; }
void dig(int x, int y) {
	if (OUT || k[i = x + W * y] || (k[i]++, s--, m[i]))return;
	for (int i = 0; i < 9; ++i - 4 || i++)f(x + i % 3 - 1, y + i / 3 - 1);
}
void set(int x, int y) {
	for (srand(m), f = tmp; c++ < B; dig(j % W, j / W), m[j] = 16, k[j]--)
		for (; m[j = rand() % (W * H)] > 9 || z == j || (m[j] = 0););
	f = dig, s += B, dig(x, y);
}
int main() {
	struct termios ot, nt;
	tcgetattr(STDIN_FILENO, &ot), nt = ot, nt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &nt);
	for (f = set, s = W * H, m = calloc(s * 2, 4), k = m + s; c - 27; j = 0) {
		c - 68 || z++, c - 65 || z--, c - 83 || (z += W), c - 87 || (z -= W);
		z = (z + W * H) % (W * H), c || (f(z % W, z / W), 0), system("clear");
		for (i = 0; j = i - z ? 32 : 62, i < W * H; ++i % W || printf("\n"))
			printf("%c%c", j, k[i] ? m[i] ? 48 + m[i] : 32 : 42);
		if (!(j = c || m[z] < 9) || s <= B || (c = getchar() & 95, 0))break;
	}
	printf("%s! %ds", j ? "you win" : "Game over", clock() / CLOCKS_PER_SEC);
  getchar(), tcsetattr(STDIN_FILENO, TCSANOW, &ot);
}

/*
31行扫雷, 1368字符, 通过修改缓冲区大小, 可移植到Linux平台运行;
ADSW移动光标, 空格挖开对应格子, 剩余格子等于雷的数量或挖到雷或按下Esc键时游戏结束;
可自定义地图尺寸(W, H), 雷的数量(B)
好像有更简单的方法...好像能一句命令就能实现类似效果
于2020.7.4上传, 2020.10.3补充说明
*/

#include <stdlib.h>
#include <conio.h>
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
	for (f = set, s = W * H, m = calloc(s * 2, 4), k = m + s; c - 27; j = 0) {
		c - 68 || z++, c - 65 || z--, c - 83 || (z += W), c - 87 || (z -= W);
		z = (z + W * H) % (W * H), c || (f(z % W, z / W), 0), system("cls");
		for (i = 0; j = i - z ? 32 : 62, i < W * H; ++i % W || _cputs("\n"))
			_cprintf("%c%c", j, k[i] ? m[i] ? 48 + m[i] : 32 : 42);
		if (!(j = c || m[z] < 9) || s <= B || (c = _getch() & 95, 0))break;
	}
	_cputs(j ? "You win!" : "Game over!"), _getch();
}

/*
24行扫雷, 1088字符, 实现了简单的功能;
ADSW移动光标, 空格挖开对应格子, 剩余格子等于雷的数量或挖到雷或按下Esc键时游戏结束;
可自定义地图尺寸(W, H), 雷的数量(B)
于2020.6.25上传, 2020.10.3补充说明并删除部分代码
删除: 结束时显示运行时间 (不影响游戏主体, 行数-1)

下面是之前的说明:

修改了一些细节，可以更方便地修改地图大小了(别设置太大了,会栈溢出),行数没变就直接覆盖原来的代码了(2020.7.4)
使用gcc编译通过(MinGW)(gcc version 8.2.0)
不仅减少了很多代码,交互也比上一次的更好了
wasd键控制光标,空格键挖开当前格子,Esc键退出
结束还会显示用时(虽然没什么用)
越界处理比较粗糙,左右越界会跨行,不过不影响体验
挖到雷时不会展示所有雷,不影响体验,就这样了
*/

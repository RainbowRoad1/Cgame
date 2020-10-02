#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define Guide(C) for ( C, i = 0; c = n[z[2]] >> i * 4 & 15, \
	j = *z + c % 4, k = z[1] + c / 4, i < 4; i++)
int W = 10, H = 25, i, j, k, c, oT, *m, z[3] = { 0 }, n[28] = {
51264, 12816, 51264, 12816, 21520, 21520, 21520, 21520, 25872, 34113,
25872, 34113, 21537, 38208, 21537, 38208, 25921, 38481, 38484, 38209,
25922, 43345, 34388, 38160, 25920, 38177, 42580, 38993
};
int move(int *v, int l) {
	Guide(*v += l) (j < 0 || j >= W || k >= H || m[k * W + j]) && (i = 5);
	return i - 4 ? *v -= l, 0 : 1;
}
void down() {
	if (move(z + 1, 1) || z[1] < 1 && (oT = 0))return;
	Guide(0) m[k * W + j] = 1, i - 3 || (z[2] = rand() % 7 * 4,z[1] = 0);
	for (*z = j = 0, i = W * H - 1; j += m[i], i >= W; i-- % W || (j = 0))
		for (k = i + W; j == W && (--k >= W || !(i += W)); m[k] = m[k - W]);
}
int main() {
	for (srand(m = calloc(W * H, 4)), c = oT = 1; oT; _sleep(50)) {
		if (_kbhit())c = _getch() & 95, c - 65 && c - 68 && c - 83 && c - 87 ||
			move(z + (c / 12 - 5), c - 87 - z[2] % 4 ? c / 6 & 1 ? 1 : -1 : 3);
		Guide((system("cls"), c - 27 || (oT = 0))) m[k * W + j] = -1;
		for (i = 0; i < W * H; ++i % W || _cputs("|\n"))
			_cputs(m[i] ? "[]" : "  "), m[i] += m[i] < 0;
		if (clock() - 1000 > oT && oT) oT = clock(), down();
	}
}

/*
30行俄罗斯方块, 1314字符, 实现了简单的功能;
AD移动, S下坠, W旋转, 某一行填满方块则消行, 当方块堆到顶层或按下Esc键时游戏结束;
可自定义地图尺寸(W, H)
在33行的版本上加以改进, 优化部分逻辑, 减缓下坠速度, 方便修改地图大小, Esc键退出
此处使用gcc编译通过, vs需要屏蔽4996号错误, 加上下面一行代码
#pragma warning(disable:4996)
于2020.6.13上传, 2020.10.2补充说明

下面是之前的说明:

修改了一些细节，可以更方便地修改地图大小和退出(Esc键),行数没变就直接覆盖原来的代码了(2020.7.4)
偷偷更新~应该没人发现吧(2020.6.13)
使用gcc编译通过(MinGW)(gcc version 8.2.0)
相比之前,这个自动下坠的速度变缓了,形状表更整洁且与地图宽无关
之前的形状表跟地图宽有关,如果要改地图大小...
*/
/*
去光标&闪烁方法(在Maze使用过的技巧)： 
1行: 把 stdlib.h 改成 windows.h 
26行: 把 system("cls") 去掉
22~23行之间插入：
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) { 25, 0 });
25~26行之间插入：
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { 0, 0 });
*/

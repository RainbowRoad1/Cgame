#include <stdlib.h>
#include <conio.h>
int main() {
	int W = 20, S = W * W, *map, z[3] = { 0 }, len = 3, i, c = 'D', C, *p;
	for (srand(map = calloc(S, 4)), C = map[1] = -1; C - 27; _sleep(100)) {
		if (_kbhit())C = _getch() & 95, C - 65 && C - 68 &&
			C - 83 && C - 87 || ((C ^ c) & 20) - 4 && (c = C);
		p = z + !!(c & 16), *p += c / 6 & 1 ? 1 : -1, *p = (*p + W) % W;
		if (C = 1, map[z[2] = *z + z[1] * W] > 1 || system("cls"))break;
		for (; map[z[2]] && (map[i = rand() % S] || (--map[i], ++len, --C)););
		for (map[z[2]] = len, i = 0; i < S; ++i % W || _cputs("|\n"))
			_cputs(map[i] > 0 && (map[i] -= C) ? "()" : map[i] ? "00" : "  ");
	}
}

/*
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

#include <windows.h>
#include <conio.h>
int bg[] = {15, 240, 144, 160, 176, 192, 208, 224, 16, 32, 48, 64, 80};
int m[36] = { 0 }, score = 0, can = 0, air = 16, c = 0, i = 6, j, *p;
void move(int *q, int v) {
	if (*q < 1 ? 0 : q[v] || (q[v] = *q, move(q + v, v), *q = can = 0))
		q[v] - *q || (q[v] = ~*q, score += 1 << *q, *q = can = 0, ++air);
}
void order(int b, int v) { b - j && ((move(m + b, v), order(b + i, v), 0)); }
int main() {
	for (p = malloc(1); i--;)m[i] = m[35 - i] = m[i * 6] = m[35 - i * 6] = -1;
	for (srand(p), free(p); (air || can) && c - 27; c = _getch() & 95) {
		c - 'A' && c - 'W' || (j = 30, i = 1, order(6, c - 'A' ? -6 : -1), 0);
		c - 'D' && c - 'S' || (j = 6, i = -1, order(30, c - 'D' ? 6 : 1), 0);
		if (!air || can || (--air, (system("cls"))))continue;
		while (m[i = rand() % 30] || (m[i] = rand() % 5 ? 1 : 2, 0));
		for (p = m + 30; --p - m - 6; *p < -1 && (*p = -*p));
		for (; ++p - m - 31; *p + 1 && _cprintf("%5d", *p ? 1 << *p : 0))
			SetConsoleTextAttribute(GetStdHandle((DWORD)-11), bg[*p % 12 + 1]),
			*p + 1 && (*p ^ p[1] && *p ^ p[6] || ++can),
			(p - m) % 6 || _cputs("\n");
		air || can || _cputs("Game over!"), _cprintf("score:%d", score);
	}
}

/*
彩色版2048, 1219字符, 给界面增加一些颜色;
ADSW使所有数字移动, 相同数字合并, 每次行动后产生新数字,
直到无法产生移动或按下Esc键时游戏结束;
于2020.9.19上传, 2020.10.3补充说明并修改部分代码

下面是之前的说明:

这个版本增加了颜色来区别不同的格子
界面比之前更小但更加直观...
也就加了2行, 挺容易的
*/

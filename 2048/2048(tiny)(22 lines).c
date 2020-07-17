#include<stdlib.h>
#include<conio.h>
int m[36] = { 0 }, score = 0, can = 0, air = 16, c = 0, i = 6, j, *p;
void move(int *q, int v) {
	if (*q < 1 ? 0 : q[v] || (q[v] = *q, move(q + v, v), *q = can = 0))
		q[v] - *q || (q[v] = ~*q, score += 1 << *q, *q = can = 0, ++air);
}
void order(int b, int v) { b - j && ((move(m + b, v), order(b + i, v), 0)); }
int wall() { return _cprintf("\n----- ----- ----- ----- \n"); }
int main() {
	for (p = malloc(1); i--;)m[i] = m[35 - i] = m[i * 6] = m[35 - i * 6] = -1;
	for (srand(p), free(p); (air || can) && c - 27; c = _getch() & 95) {
		c - 'A' && c - 'W' || (j = 30, i = 1, order(6, c - 'A' ? -6 : -1), 0);
		c - 'D' && c - 'S' || (j = 6, i = -1, order(30, c - 'D' ? 6 : 1), 0);
		if (!air || can || (--air, (system("cls"))))continue;
		while (m[i = rand() % 30] || (m[i] = rand() % 5 ? 1 : 2, 0));
		for (p = m + 30; --p - m - 6; *p < -1 && (*p = -*p));
		for (; ++p - m - 31; *p + 1 && _cprintf("%5d|", *p ? 1 << *p : 0))
			*p + 1 && (*p ^ p[1] && *p ^ p[6] || ++can), (p - m) % 6 || wall();
		air || can || _cputs("Game over!"), _cprintf("score:%d", score);
	}
	//for (_cputs("\n### Press space to exit ###\n"); _getch() - ' ';);
}

//adsw移动, Esc退出, 差不多这样了
//第22行方便测试用的, 去掉不影响整体
//由于2048本身逻辑挺复杂的, 压缩花了很长时间...
//这里感谢群里某个大佬提供的边界检测思路(然后又重构了一遍233)
//*大佬不愿透露名字

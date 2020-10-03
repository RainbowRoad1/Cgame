#include<stdlib.h>
#include<conio.h>
int m[36] = { 0 }, s = 0, can = 0, air = 16, c = 0, i = 6, j, *p;
void move(int *q, int v) {
	if (*q < 1 ? 0 : q[v] || (q[v] = *q, move(q + v, v), *q = can = 0))
		q[v] - *q || (q[v] = ~*q, s += 1 << *q, *q = can = 0, ++air);
}
void index(int b, int v) { b - j && ((move(m + b, v), index(b + i, v), 0)); }
int main() {
	for (p = malloc(1); i--;)m[i] = m[35 - i] = m[i * 6] = m[35 - i * 6] = -1;
	for (srand(p), free(p); (air || can) && c - 27; c = _getch() & 95) {
		c - 'A' && c - 'W' || (j = 30, i = 1, index(6, c - 'A' ? -6 : -1), 0);
		c - 'D' && c - 'S' || (j = 6, i = -1, index(30, c - 'D' ? 6 : 1), 0);
		if (!air || can || (--air, (system("cls"))))continue;
		while (m[i = rand() % 30] || (m[i] = rand() % 5 ? 1 : 2, 0));
		for (p = m + 30; --p - m - 6; *p < -1 && (*p = -*p));
		for (; ++p - m - 31; *p + 1 && _cprintf("%5d|", *p ? 1 << *p : 0))
			*p + 1 && (*p ^ p[1] && *p ^ p[6] || ++can),
			(p - m) % 6 || _cputs("\n----- ----- ----- -----\n");
		air || can || _cputs("Game over!"), _cprintf("score:%d", s);
	}
	//for (_cputs("\n### Press space to exit ###\n"); _getch() - ' ';);
}
/*
22行2048, 1085字符(不包括注释), 实现了简单的功能;
ADSW使所有数字移动, 相同数字合并, 每次行动后产生新数字,
直到无法产生移动或按下Esc键时游戏结束;
在28行的版本上加以改进, 优化部分逻辑, 减少代码量, 增加Esc键退出
于2020.7.17上传, 2020.10.3补充说明并修改部分代码

下面是之前的说明:
*/

//adsw移动, Esc退出, 差不多这样了
//第22行方便测试用的, 去掉不影响整体
//由于2048本身逻辑挺复杂的, 压缩花了很长时间...
//这里感谢群里某个大佬提供的边界检测思路(然后又重构了一遍233)
//*大佬不愿透露名字

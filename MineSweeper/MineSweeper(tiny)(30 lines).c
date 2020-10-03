#include<stdlib.h>
#include<stdio.h>
#define OUTSIDE(x, y) (x < 0 || 8 < x || y < 0 || 8 < y)
int map[81] = {0}, mark[81] = {0}, count = 81, bomb = -4, i, j, k;
int node[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, -1, -1, 1, -1, -1, 1, 1, 1};
void setBomb(int x, int y) {
	for (int i = 0, j, k, m, n; i < -bomb && (j = rand() % 9, k = rand() % 9, 1);)
		if (!(map[9 * k + j] == 9 || j == x && k == y) && (i++, map[9 * k + j] = 9))
			for (int i = 0; i < 8 && (m = j + node[i][0], n = k + node[i][1], 1); i++)
				!(OUTSIDE(m, n) || map[9 * n + m] == 9) && map[9 * n + m]++;
}
void open(int x, int y) {
	if (OUTSIDE(x, y) || mark[9 * y + x] > 0)return;
	if (mark[9 * y + x] = 1, count--, map[9 * y + x] > 0)return;
	for (int i = 0; i < 8; i++)open(x + node[i][0], y + node[i][1]);
}
int main() {
	system("mode con:cols=18 lines=12");
	for (srand((unsigned)malloc(1)); 1; open(j, k), system("cls")) {
		for (i = 0; i < 81; i++)
			if (!printf(mark[i] || !bomb ? map[i] ? "" : "  " : " *"))
				printf(" %c", map[i] < 9 ? map[i] + 48 : '@');
		if (count <= bomb && printf("You win!\n"))break;
		else if (!bomb&&printf("Game over!\n"))break;
		printf("剩余%d：\n输入坐标：", count), scanf_s("%d%d", &j, &k);
		bomb < 0 && (setBomb(j, k), bomb = -bomb), map[k * 9 + j] - 9 || (bomb = 0);
	}
	system("pause");
}

/*
29行扫雷, 1316字符, 实现了简单的功能;
输入坐标, 挖开对应格子, 剩余格子等于雷的数量或挖到雷时游戏结束;
可自定义雷的数量(bomb, 取相反数), 改地图尺寸很麻烦, 比较鸡肋...
这个输入坐标的方式不太友好...应该不会有人喜欢这种方式吧?
现在的tiny版本改变了交互方式, 采用虚拟光标的形式来挖雷
额外提及几点:
1. malloc()的返回值被忽略, 会不会造成内存泄漏?
这个其实没什么好担心的, 又不是在循环里执行, 程序结束都释放了
2. 关于移植到其他平台
都已经有Linux的版本了...

于2020.2.6上传, 2020.10.3补充说明
*/

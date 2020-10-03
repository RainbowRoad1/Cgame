#include<stdlib.h>
#include<conio.h>
int map[16] = {0}, score = 0, game = 1, c, i, j, k;
const char* wall[4] = { "\n----- ----- ----- -----\n","|","|","|" };
void move(int i,int v) {
	if (i + v < 0 || 15 < i + v || !map[i])return;
	if ((v == 1 || v == -1) && i / 4 - (i + v) / 4)return;
	if (map[i + v] == map[i])map[i + v] *= -2, score += map[i], map[i] = k = 0;
	if (!map[i + v])map[i + v] = map[i], map[i] = k = 0, move(i + v, v);
}
void order(int end,int i,int v) {
	for (int begin = end == 16 ? 0 : 15; begin - end; begin += i)move(begin, v);
}
int main() {
	system("mode con: cols=23 lines=9");
	for (srand((unsigned)malloc(1)), c = j = 0; game; j = k = 1, c = _getch()) {
		if (c == 'a' || c == 'w')order(16, 1, c == 'a' ? -1 : -4);
		else if (c == 'd' || c == 's')order(-1, -1, c == 'd' ? 1 : 4);
		for (i = 0; i < 16; i++)map[i] < 0 && (map[i] = -map[i]), map[i] || (j = 0);
		do if (i = rand() % 16, j || k)break;
		while (map[i] || (map[i] = rand() % 5 ? 2 : 4, 0));
		for (i = 0, system("cls"); j && (i < 15 || (game = 0)); i++)
			if (i < 12 && map[i] == map[i + 4] ||
				i + 1 & 3 && map[i] == map[i + 1])break;
		if (game || _cprintf("Game over!"))_cprintf("score:%d", score);
		for (i = 0; i < 16; i++)_cprintf("%s%5d", wall[i & 3], map[i]);
	}
}

/*
28行2048, 1290字符, 实现了简单的功能;
adsw(不支持大写)使所有数字移动, 相同数字合并, 
每次行动后产生新数字, 直到无法产生移动时游戏结束;
没想到当时真能做出来...
当时受到B站观众的鼓励, 连着肝了好几期视频, 很快就灵感枯竭了(雾)
额外提及几点:
1. malloc()的返回值被忽略, 会不会造成内存泄漏?
这个其实没什么好担心的, 又不是在循环里执行, 程序结束都释放了
2. 关于移植到其他平台
conio.h并不属于标准库, 输出可以用stdio.h里的printf()
输入可能麻烦点, 可使用getchar()代替getch()
然后修改缓冲区大小实现getch()的效果
相比贪吃蛇和俄罗斯方块, 移植更加简单

于2020.2.17上传, 2020.10.3补充说明
*/
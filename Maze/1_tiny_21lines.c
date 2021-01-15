#include <stdlib.h>
#include <conio.h>
int W = 15, S, i, c = 81, z, e, *m, *L, l[4] = {1, -1};
void init(){
	for (i = S; i-- || (c = m[i = rand() % S] == 2, e = 0);)
		m[i] = 2 + ((i + 1) % W < 2) + (i % (S - W) < W);
	for (c && (L[e++] = i); e && (z = L[i = rand() % e], 1);)
		for (L[i] = L[--e], i = m[z] & 3 ? m[z] = 0 : 4; i < 4; ++i)
			c = z + l[i], m[c] & 3 && ++m[c], m[c] & 3 && (L[e++] = c);
	for (i = c ? W : S; i >= S ? init(), 0 : m[i - W]; i += W)
		m[i] & 3 | m[S - 1 - i] & 3 || (m[z = i] = m[e = S - 1 - i] = 0);
}
int main(){
	srand(m = calloc(S = W * W, 4)), L = calloc(S, 4), l[2] -= l[3] = W;
	for (; c - 81 && z - e ? 0 : init(), c - 27; c = _getch() & 95){
		c - 87 || m[z - W] || (z -= W), c - 68 || m[z + 1] || ++z;
		c - 83 || m[z + W] || (z += W), c - 65 || m[z - 1] || --z;
		for (i = system("cls"); i < S; ++i % W || _cputs("\n"))
			_cputs(i - z ? m[i] ? "[]" : "  " : "<>");
	}
}

/*
25行迷宫, 931字符, 实现了简单的功能;
ADSW移动, 按下Q键或到达另一端自动刷新, 按下Esc键时游戏结束;
可自定义地图尺寸(W), 这个尺寸包括边界的墙
相比之前的版本, 这个生成的迷宫更加复杂自然...
可以说完全换了一种算法生成
2021.1.15
	调整代码，减两行
2021.1.1
	魔改算法, 减一行, 生成的迷宫更加自然?
2020.12.19
	压缩简化, 减一行
2020.12.13
	上传
*/

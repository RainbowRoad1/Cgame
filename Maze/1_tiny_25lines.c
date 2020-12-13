#include <stdlib.h>
#include <conio.h>
int W = 15, S, i, c = 0, z = 0, e = 0, *m, *p, l[4] = {1, -1};
int k[] = {1734, 2505, 4818, 6360, 8673, 9444};
void dig(int *v){
	short n = (k[rand() % 6] >> rand() % 4 * 2 & 255) | 256;
	for (*v = 0, i = 0; p = v + l[i], i < 4; ++i)*p & 3 && ++*p;
	for (; p = v + l[n & 3], n; n >>= 2)*p & 3 && (dig(p), 0);
}
void init(){
	for (i = S; --i; i % W || (m[i--] = 3, m[i--] = 3), m[i] = 2);
	for (i = 0; i < W; m[i] = m[S - i - 1] = 3, ++i);
	m[i = rand() % S] - 2 ? i = S : dig(m + i);
	for (i = 0; (i += W) < S && m[i] & 3 | m[S - 1 - i] & 3;);
	i >= S ? init() : (m[z = i] = m[e = S - 1 - i] = 0);
}
int main(){
	srand(m = calloc(S = W * W, 4)), l[2] = W, l[3] = -W;
	for (; z - e && c - 81 ? 0 : init(), c - 27; c = _getch() & 95){
		c - 87 || m[z - W] || (z -= W), c - 68 || m[z + 1] || ++z;
		c - 83 || m[z + W] || (z += W), c - 65 || m[z - 1] || --z;
		for (i = system("cls"); i < S; ++i % W || _cputs("\n"))
			_cputs(i - z ? m[i] ? "[]" : "  " : "<>");
	}
}

/*
25行迷宫, 1026字符, 实现了简单的功能;
ADSW移动, 按下Q键或到达另一端自动刷新, 按下Esc键时游戏结束;
可自定义地图尺寸(W), 这个尺寸包括边界的墙
相比之前的版本, 生成的迷宫更加复杂自然...
可以说完全换了一种算法生成
2020.12.13
	上传
*/

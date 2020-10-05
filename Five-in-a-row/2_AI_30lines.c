#include <stdlib.h>
#include <conio.h>
int W = 13, S, *m, z = 0, c = 1, r = 2, M = 0, i, j, k, *p;
int *sum(int *v, int l) { return *v - v[l] ? v + l : sum(v + l, l); }
void down(int v) {
	for (m[v] = r ^= 3, i = 2; j = i % 3 - 1 + (i / 3) * W, i < 6; ++i) {
		p = sum(m + v, j), k = (p - sum(m + v, -j)) / j;
		*p || (p[S * r] += 1 << k), p -= k * j, *p || (p[S * r] += 1 << k);
		m[v + S] = m[v + S * 2] = 0, k > 5 && (r ^= 3, r += 4, i = 8);
	}
}
void ai() {
	for (j = k = 0, i = S; i < S * 3 || (k = rand() % k, k || ++k, 0);)
		j == m[i] && ++k, j < m[i] && (j = m[i], k = 1), ++i;
	for (i = S; k && i < 3 * S || (down(i % S), 0);)m[++i] == j && --k;
}
int main() {
	for (W += 2, S = W * W, m = calloc(i = S * 3, 4), srand((int)m); i--;)
		i % W && -~i % W && !(i % S < W || (i + W) % S < W) || (m[i] = -1);
	for (z = S / 2; r < 4 && c - 27 && !system("cls"); c = _getch() & 95) {
		c - 87 || m[z - W] + 1 && (z -= W), c - 68 || m[++z] + 1 || --z;
		c - 83 || m[z + W] + 1 && (z += W), c - 65 || m[--z] + 1 || ++z;
		if (!c)M - 2 ? !m[z] && (down(z), r < 4 && M && (ai(), 0)) : ai();
		for (i = W; i < S - W; ++i % W || (_cprintf("%d\n", i / W - 1)))
			m[i] + 1 && _cprintf("%c%c", " >"[i == z], " 0@"[m[i]]);
		for (i = 1, c - 81 || ++M; ++i < W;)_cprintf(" %c", 95 + i);
		M %= 3, _cprintf("\n%s|", "PvP\0PvE\0EvE" + M * 4);
		_cputs(r & 1 ? "White" : "Black"), r < 4 || _cputs(" win!");
	}
}

/*
操作：adsw键移动，空格下子，q键切换模式，Esc退出
规则：黑方先手，先达成五连的获胜
补充：
1. 模式有三种：
  PvP(Player VS Player)，玩家对战玩家，均由玩家自行下子
  PvE(Player VS Environment)，玩家对战环境，玩家下子后自动再下一子
  EvE，不解释，按一下自动下一子，不受光标影响
2. '@'是白棋,'O'是黑棋(对应25行的64和79,可以自己改成自己喜欢的符号
3. 棋盘大小可以自己改(3行的W)(固定长宽比1:1)
4. 光标不能越界，和上一个版本不同
5. 关于ai的棋力...emm能围堵已经不错了，之后还会做更强的ai
6. 感谢群里某个热心群友提供的大量思路(要求匿名)
额外：
花了半个月完成，从上百行到30行...感觉有些不可思议
参考了很多代码，都是几千行，使我望而生畏，大量的逻辑与机制，毫无重用的部分...
最后还是使用了自己全新的思路，结合了部分群友的建议后，肝了几天几夜完成了
行数和棋力之间不得不做出取舍，很显然我选择了行数，同时保留了最基础的评估部分
本来还觉得百行丢人，加上新视频没有达到预期，本来还想放弃这个作品的（雾）

于2020.8.10上传
*/

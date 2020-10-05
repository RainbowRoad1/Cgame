#include <windows.h>
#include <conio.h>
#include <stdio.h>
int W = 13, S, M = 0, *m, c = 1, r = 2, z, i, j, k, *p;
int *sum(int *v, int l) { return *v - v[l] ? v + l : sum(v + l, l); }
void down(int v) {
	for (m[v] = r ^= 3, i = 2; j = i % 3 - 1 + i / 3 * W, i < 6; ++i) {
		p = sum(m + v, j), k = (p - sum(m + v, -j)) / j;
		*p || (p[S * r] += 1 << k), p -= k * j, *p || (p[S * r] += 1 << k);
		m[v + S] = m[v + S * 2] = 0, k > 5 && (r ^= 3, r += 4, i = 8);
	}
}
void ai() {
	for (j = k = 0, i = S; i < 3 * S || (k = rand() % k, k || ++k, 0);)
		j == m[i] && ++k, j < m[i] && (j = m[i], k = 1), ++i;
	for (i = S; k && i < 3 * S || (down(i % S), 0);)m[++i] == j && --k;
}
int main() {
	for (W += 2, S = W * W, m = calloc(i = S * 3, 4), srand((int)m); i--;)
		i % W && -~i % W && !(i % S < W || (i + W) % S < W) || (m[i] = -1);
	SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO) { 25 });
	for (z = S / 2, system("cls"); r < 4 && c - 27; c = _getch() & 95) {
		c - 87 || m[z - W] + 1 && (z -= W), c - 68 || m[++z] + 1 || --z;
		c - 83 || m[z + W] + 1 && (z += W), c - 65 || m[--z] + 1 || ++z;
		if (!c)M - 2 ? !m[z] && (down(z), r < 4 && M && (ai(), 0)) : ai();
		SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD) { 0 });
		for (i = W; i < S - W; ++i % W || _cprintf("%d\n", i / W - 1))
			SetConsoleTextAttribute(GetStdHandle((DWORD)-11), i - z ? 15 : 175),
			m[i] + 1 && printf(". \0○\0●" + m[i] * 3);
		for (i = 1, c - 81 || ++M; ++i < W;)_cprintf(" %c", 95 + i);
		M %= 3, _cprintf("\n%s|", "PvP\0PvE\0EvE" + M * 4);
		_cputs(r & 1 ? "White" : "Black"), r < 4 || _cputs(" win!");
	}
}

/*
彩色版五子棋, 1649字符, 给界面增加一些颜色;
于2020.9.4上传
*/
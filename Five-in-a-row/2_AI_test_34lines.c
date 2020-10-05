#include <windows.h>
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
    SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO){25});
    for (z = S / 2, system("cls"); r < 4 && c - 27; c = _getch() & 95) {
        c - 87 || m[z - W] + 1 && (z -= W), c - 68 || m[++z] + 1 || --z;
        c - 83 || m[z + W] + 1 && (z += W), c - 65 || m[--z] + 1 || ++z;
        if (!c)M - 2 ? !m[z] && (down(z), r < 4 && M && (ai(), 0)) : ai();
        SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD){0});
        for (i = -~W; i < S - W; -~m[++i] || (_cprintf("%d\n", i++ / W), ++i))
            _cprintf("%c%c", i - z ? 32 : 62, m[i] ? m[i] - 1 ? 64 : 79 : 32);
        for (i = 0; i < W - 2 || (_cputs("\n")); ++i)_cprintf(" %c", 97 + i);
		c - 'Q' || (M = ++M % 3), _cputs(M ? M - 1 ? "EvE" : "PvE" : "PvP");
		_cprintf("|%s", r & 1 ? "White" : "Black"), r < 4 || _cputs(" win!");
        for (i = S; i < S * 3; ++i % W || (_cputs("\n")))
        	m[i] + 1 && _cprintf("%2d", m[i] >> 2);
	}
}

/*
嗯，多了一点东西，方便测试之类的
1. 光标定位，一直摁空格也不会目害了
2. 显示评估表，了解评估是怎么运作的（非常的智障）
于2020.8.10上传
*/

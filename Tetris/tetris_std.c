#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
#define W 7
#define H 15
const int ALL = (4 << W) - 1, AIR = 2 << W | 1, CL = W * 2 + 2;
char o[(W * 2 + 2) * H], *c = o + (W * 2 + 2) * H;
int m[H + 2], x = 1, y = 1, t = 0, i, j, tot = 0;
int n[28][4] = {{15, 0, 0, 0}, {1, 1, 1, 1}, {15, 0, 0, 0}, {1, 1, 1, 1},
                {3, 3, 0, 0},  {3, 3, 0, 0}, {3, 3, 0, 0},  {3, 3, 0, 0},
                {1, 7, 0, 0},  {6, 2, 2, 0}, {0, 7, 4, 0},  {2, 2, 3, 0},
                {0, 7, 1, 0},  {2, 2, 6, 0}, {4, 7, 0, 0},  {3, 2, 2, 0},
                {2, 7, 0, 0},  {2, 6, 2, 0}, {0, 7, 2, 0},  {2, 3, 2, 0},
                {6, 3, 0, 0},  {1, 3, 2, 0}, {6, 3, 0, 0},  {1, 3, 2, 0},
                {3, 6, 0, 0},  {2, 3, 1, 0}, {3, 6, 0, 0},  {2, 3, 1, 0}};
void fill(char c1, char c2) {
    for (c = (y - 2) * CL + x * 2 + 6 + o, i = 0; i < 4; ++i)
        for (c += CL - 8, j = 0; j < 4; ++j, c += 2)
            if (n[t][i] >> j & 1) *c = c1, c[1] = c2;
}
void move(int *v, int w) {
    for (*v += w, i = 0; i < 4 && !(m[i + y] & (n[t][i] << x));) ++i;
    if (i == 4 || (*v -= w, v != &y) || (x | y) == 1 && !(y = 0)) return;
    for (fill('[', ']'), i = 4; i--;) m[y + i] |= n[t][i] << x;
    x = 1, y = 1, t = rand() % 28, c = o + CL * H - 1;
    for (i = H; m[i] != AIR && m[i] != ALL; --i) c -= CL;
    for (j = 0; m[i] != AIR; --i)
        if (m[i] == ALL ? ++j, 0 : (m[i + j] = m[i], 1))
            for (c -= 2; *c != '\n'; --c) *c = c[-CL * j];
    for (i += j; m[i] != AIR; m[i] = AIR, --i)
        for (; *(c -= 2) != '\n';) *c = c[-1] = '.';
}
int main() {
    for (m[0] = AIR, m[H + 1] = ALL, i = H; 0 < i; m[i] = AIR, --i)
        for (j = CL - 2, *--c = '\n', *--c = '#'; 0 < j; --j) *--c = '.';
    for (o[CL * H - 1] = '\0', srand((unsigned)time(0)); y; _sleep(100)) {
        if (_kbhit()) switch (fill('.', '.'), _getch() & 95) {
            case 27: y = 0; continue;
            case 'A': move(&x, -1); break;
            case 'D': move(&x, 1); break;
            case 'S': move(&y, 1); break;
            case 'W': move(&t, t & 3 ^ 3 ? 1 : -3); break;
            case 0:
                while (move(&y, 1), y > 1) {}
            }
        else if (++tot == 10) fill('.', '.'), move(&y, 1);
        else continue;
        tot = 0, fill('[', ']'), system("cls"), printf(o);
    }
    printf("\nGame over!\n");
}

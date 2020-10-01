#include <windows.h>
#include <conio.h>
int main() {
    int W = 20, S = W * W, * m, z[2] = { 0 }, l = 3, i, c = 'D', C, * p, f;
    SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO){25});
    for (srand(m = calloc(S, 4)), C = m[1] = -1; C - 27; Sleep(100)) {
        if (_kbhit())C = _getch() & 95, C - 65 && C - 68 &&
            C - 83 && C - 87 || (C ^ c) & 20 ^ 4 && (c = C);
        p = z + !!(c & 2), * p += c / 3 & 2, * p = (-- * p + W) % W;
        f = 1, * (p = m + *z + z[1] * W) > 0 && (C = 27);
        for (; *p && (m[i = rand() % S] || (--m[i], ++l, --f)););
        SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD){0});
        for (i = 0, *p = l; i < S; _cputs("  "), ++i % W || _cputs("\n"))
            SetConsoleTextAttribute(GetStdHandle((DWORD)-11),
                m[i] > 0 ? m[i] -= f, 192 : m[i] ? 160 : 240);
    }
}

/*
在14行贪吃蛇的基础上加以修改
界面比之前舒服了许多...
使用了部分c99特性
2020.9.30
*/
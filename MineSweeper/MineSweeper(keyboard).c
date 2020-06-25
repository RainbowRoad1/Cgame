#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define OUT (x < 0 || 9 <= x || y < 0 || 9 <= y)
int map[81] = {0}, mark[81] = {0}, count = 81, z, c, i, j, s, (*f)(int, int);
void tmp(int x, int y) { OUT || map[x + 9 * y] - 16 && map[x + 9 * y]++; }
void dig(int x, int y){
	if (OUT || mark[i = x + y * 9] || (mark[i]++, count--, map[i]))return;
	for (int i = 0; i < 9; ++i - 4 || i++)f(x + i % 3 - 1, y + i / 3 - 1);
}
void set(int x, int y){
	for (srand(time(0)); c++ < s; dig(j % 9, j / 9), map[j] = 16, mark[j]--)
		for (f = tmp; map[j = rand() % 81] > 9 || z == j || (map[j] = 0););
	f = dig, count += s, dig(x, y);
}
int main(){
	for (f = set, c = 1, z = 40 ,s = 10; c - 27;c = getch() & 95){
		c - 68 || z++, c - 65 || z--, c - 83 || (z += 9), c - 87 || (z -= 9);
		z = (z + 81) % 81, c || (f(z % 9, z / 9), 0), system("cls");
		for (i = 0; j = i - z ? 32 : 62, i < 81; 1, ++i % 9 || _cputs("\n"))
			_cprintf("%c%c", j, mark[i] ? map[i] ? 48 + map[i] : 32 : 42);
		if((j = count <= 10) || c == 0 && map[z] > 9)break;
	}
	_cprintf("%s! %ds", j ? "you win" : "Game over", clock() / 1000), getch();
}

/*
使用gcc编译通过(MinGW)(gcc version 8.2.0)
不仅减少了很多代码,交互也比上一次的更好了
wasd键控制光标,空格键挖开当前格子,Esc键退出
结束还会显示用时(虽然没什么用)
越界处理比较粗糙,左右越界会跨行,不过不影响体验
挖到雷时不会展示所有雷,不影响体验,就这样了
*/

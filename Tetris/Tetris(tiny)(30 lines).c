#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define Guide(C) for ( C, i = 0; c = n[z[2]] >> i * 4 & 15, \
	j = *z + c % 4, k = z[1] + c / 4, i < 4; i++)
int i, j, k, c , oT, m[250] = {0}, z[3] = {0}, n[28] = {
51264, 12816, 51264, 12816, 21520, 21520, 21520, 21520, 25872, 34113, 
25872, 34113, 21537, 38208, 21537, 38208, 25921, 38481, 38484, 38209,
25922, 43345, 34388, 38160, 25920, 38177, 42580, 38993
};
int move(int *v, int l){
	Guide(*v += l) (j < 0 || j > 9 || k > 24 || m[k * 10 + j]) && (i = 5);
	return i - 4 ? *v -= l , 0 : 1;
}
void down(){
	if (move(z + 1, 1) || z[1] < 1 && (exit(0), 0))return;
	Guide(0) m[k * 10 + j] = 1;
	for (i = 249, j = 0 ,z[1] = 25; j += m[i], i > 9; i-- % 10 || (j = 0))
		for (k = i + 10; j == 10 && (k-- > 9 || !(i += 10)); m[k] = m[k - 10]);
}
int main(){
	srand((int)time(0)), system("mode con: cols=20 lines=25"),oT = 0;
	for (; z[1] < 25 || !(z[2] = rand() % 7 * 4, *z = z[1] = 0); _sleep(50)) {
		if (_kbhit())c = _getch() & 95, c - 65 && c - 68 && c - 83 && c - 87 ||
			move(z + (c / 12 - 5), c - 87 - z[2] % 4 ? c / 6 & 1 ? 1 : -1 : 3);
		Guide(system("cls")) m[k * 10 + j] = -1;
		for (i = 0; i < 250; i++)_cputs(m[i] ? "[]" : "  "), m[i] += m[i] < 0;
		if (clock() - 1000 > oT) oT = clock(), down();
	}
}

/*
偷偷更新~应该没人发现吧(2020.6.13)
使用gcc编译通过(MinGW)(gcc version 8.2.0)
相比之前,这个自动下坠的速度变缓了,形状表更整洁且与地图宽无关
之前的形状表跟地图宽有关,如果要改地图大小...
*/
/*
去光标&闪烁方法(在Maze使用过的技巧)： 
1行: 把 stdlib.h 改成 windows.h 
26行: 把 system("cls") 去掉
22~23行之间插入：
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) { 25, 0 });
25~26行之间插入：
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { 0, 0 });
*/

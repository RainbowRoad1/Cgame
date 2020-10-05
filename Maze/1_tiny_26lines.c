#include<windows.h>
#include<conio.h>
#define Long 21
int c, i, place = Long, map[Long * Long] = { 0 };
int move[8] = { -1,1,-Long,Long,'a','d','w','s' };
void dig(int v) {
	int a[4] = { 2,-2,2 * Long,-2 * Long }, i = 0, j;
	for (; j = rand() % 4, i < 4; i++)i - j && (a[i] ^= a[j] ^= a[i] ^= a[j]);
	for (map[v] = 1, i = 0; i < 4; i++) {
		if (v + a[i] < 0 || Long * Long < v + a[i] || map[v + a[i]])continue;
		if ((a[i] == 2 || a[i] == -2) && v / Long - (a[i] + v) / Long)continue;
		map[v + a[i] / 2] = 1, dig(v + a[i]);
	}
}
int main() {
	srand((unsigned)malloc(!system("mode con:cols=42 lines=21")));
	SetConsoleCursorInfo(GetStdHandle((DWORD)-11), &(CONSOLE_CURSOR_INFO){25});
	dig(Long + 1), map[Long] = map[Long*Long - Long - 1] = 1;
	for (c = 0; c = _getch(), place - Long * Long + Long + 1;) {
		for (i = 0; c - move[i + 4] && i < 4; i++);
		i < 4 && map[place + move[i]] && (place += move[i]);
		SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD){0});
		for (i = 0; i < Long*Long; i++)
			_cputs(i - place ? map[i] ? "  " : "[]" : "<>");
	}
}

/*
26行走迷宫, 1110字符, 实现了简单的功能;
adsw移动(不支持大写), 直到移动到右下角时游戏结束;
可自定义地图尺寸(Long)
这个算是最水的一个作品了...实现的效果并不是很好
目前打算重写一遍, 让自动生成的迷宫更加自然
由于去掉闪烁多了两行代码, 和对应视频内容有一点出入
于2020.4.24上传, 2020.10.3补充说明并修改部分代码
*/
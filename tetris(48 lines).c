#include<stdlib.h>																	//引用头文件
#include<conio.h>
#pragma warning(disable:4996)
int T, X, Y, map[25][10] = { 0 }, i, j, a, c, node[28][4][2] = {
	-1,0,0,0,1,0,-1,-1,0,1,0,0,0,-1,1,-1,1,1,-1,0,0,0,1,0,-1,1,0,1,0,0,0,-1,-1,0,0,0,1,0,1,-1,0,1,1,1,0,0,0,-1,-1,1,-1,0,0,0,1,0,
	0,1,0,0,0,-1,-1,-1,-1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,-1,-1,1,0,1,0,0,1,0,1,1,0,0,1,0,0,-1,0,1,1,1,-1,0,0,0,0,1,0,0,1,0,1,-1,
	0,1,1,1,-1,0,0,0,0,1,0,0,1,0,1,-1,-1,0,0,0,1,0,0,-1,0,1,0,0,1,0,0,-1,0,1,-1,0,0,0,1,0,0,1,-1,0,0,0,0,-1,0,2,0,1,0,0,0,-1,
	-1,0,0,0,1,0,2,0,0,2,0,1,0,0,0,-1,-1,0,0,0,1,0,2,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,1,1,0,0,1,0
};
void move(int* v,int l){
	for (*v += l, i = 0; i < 4; i++)
		if ((node[T][i][0] + X < 0 || node[T][i][0] + X > 9 || map[node[T][i][1] + Y][node[T][i][0] + X]) && (*v -= l))return;
}
void down(int line,int temp) {
	for (Y += 1, i = 0; i < 4; i++)
		if (node[T][i][1] + Y > 24 || map[node[T][i][1] + Y][node[T][i][0] + X])line = 1;
	if (line&&--Y) {
		if (Y == 1)exit(0);
		for (i = 0; i < 4; i++)map[node[T][i][1] + Y][node[T][i][0] + X] = 1;
		for (line = 24; line > 0 || (a = 0); line--) {
			for (temp = 0, i = 0; i < 10; temp += map[line][i++]);
			if (temp != 10)continue;
			for (i = line++; i > 1; i--)
				for (j = 0; j < 10; j++)
					map[i][j]=map[i-1][j];
		}
	}
}
int main() {
	system("mode con: cols=20 lines=25");
	srand((unsigned)malloc(sizeof(int)));
	while (T = rand() % 7 * 4, (a=1))
		for (X = 4, Y = 1; down(0,0), a==1;_sleep(150)) {
			if (_kbhit() && (c = _getch())) {
				if (c == 'a' || c == 'A')move(&X,-1);
				else if (c == 'd' || c == 'D')move(&X,1);
				else if (c == 'w' || c == 'W')move(&T, (T % 4) < 3 ? 1 : -3);
				else if (c == 's' || c == 'S')while(down(0,0),a);
				_sleep(10);
			}
			system("cls");
			for (i = 0; i < 4 && (map[node[T][i][1] + Y][node[T][i][0] + X] = 1); i++);
			for (i = 0; i < 25; i++)
				for (j = 0; j < 10; j++)
					(map[i][j]) ? _cputs("[]") : _cputs("  ");
			for (i = 0; i < 4 && (map[node[T][i][1] + Y][node[T][i][0] + X] = 0,1); i++);
		}
}

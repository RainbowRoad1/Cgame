#include<stdlib.h>
#include<conio.h>
#pragma warning(disable:4996)
int main() {
	system("mode con: cols=60 lines=31");
	int hX = 7, hY = 7, num = 4, map[900] = { 0 }, i = 0;
	char c = 'd', cl = 'd';
	srand((unsigned)&map);
	for (map[rand() % 900] = -1; system("cls"), 1; _sleep(50)) {
		if (_kbhit())cl = _getch();
		if ((cl == 'a'&&c != 'd') || (cl == 'd'&&c != 'a') || (cl == 'w'&&c != 's') || (cl == 's'&&c != 'w'))c = cl;
		if (c == 'a'&&--hX < 0)break;
		else if (c == 'd'&&++hX == 30)break;
		else if (c == 'w'&&--hY < 0)break;
		else if (c == 's'&&++hY == 30)break;
		if (map[hY * 30 + hX] > 1)break;
		if (map[hY * 30 + hX] < 0 && num++)map[rand() % 900] = -1;
		else for (int i = 0; i < 900; i++)if (map[i] > 0)map[i] -= 1;
		for (map[hY * 30 + hX] = num + 1; i < 900 || (i = 0); i++) {
			if (!map[i])cputs("  ");
			else if (map[i] > 0)cputs("()");
			else cputs("00");
		}
	}
}

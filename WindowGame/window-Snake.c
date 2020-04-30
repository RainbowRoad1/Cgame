#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define windowWidth 120
#define windowHeight windowWidth //单个窗口长和宽
#define mapLines (GetSystemMetrics(SM_CYSCREEN) / windowWidth)
#define mapCols (GetSystemMetrics(SM_CXSCREEN) / windowHeight) //地图行数和列数
#define mapMax (mapLines * mapCols)//地图总共的格子数
#define Delay 100 //延迟
#if (windowWidth < 120)
#define WindowStyle WS_POPUP
#else
#define WindowStyle WS_TILEDWINDOW
#endif
const char* myclass = "Snake";
int hX = 0, hY = 0, len = 4, c = 'd', cl = 'd', i = 0, *map;
HANDLE hOut;
COORD origin = { 0, 0 };
HWND *screen;
MSG msg;
//信息循环
LRESULT CALLBACK WndProc(HWND window, unsigned int msg, WPARAM wp, LPARAM lp)
{
	return DefWindowProc(window, msg, wp, lp);
}
//注册窗口
ATOM MyRegisterClass()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_DBLCLKS;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(0);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = 0;
	wc.lpszClassName = myclass;
	wc.hIconSm = LoadIcon(0, IDI_APPLICATION);
	return RegisterClassEx(&wc);
}
//创建窗口
HWND addWindow(int x, int y, int width, int height)
{
	HWND window = CreateWindowEx(0, myclass, "title", WindowStyle ,
		x, y, width, height, 0, 0, GetModuleHandle(0), 0);//创建窗口
	if (!window)return 0;//窗口是否成功创建
	return window;
}
//设置控制台大小
void setConsoleSize(int lines, int cols)
{
	COORD size = { lines,cols };
	SMALL_RECT rect = { 0,0,size.X - 1,size.Y - 1 };
	SetConsoleWindowInfo(hOut, 1, &rect);
	SetConsoleScreenBufferSize(hOut, size);
	SetConsoleWindowInfo(hOut, 1, &rect);
}
//隐藏光标
void hideCursor()
{
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOut, &CursorInfo);
	CursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hOut, &CursorInfo);
}

int main()
{
	srand((unsigned)time(0)); //初始化随机数种子
	if (!MyRegisterClass())return GetLastError();//注册窗口
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	setConsoleSize(mapCols * 2, mapLines + 1);
	hideCursor();
	map = (int*)malloc(mapMax * sizeof(int));
	screen = (HWND*)malloc(mapMax * sizeof(HWND)); //分配
	for (i = 0; i < mapMax; i++) //初始化
	{
		map[i] = 0;
		screen[i] = addWindow(i % mapCols * windowWidth, i / mapCols * windowHeight, windowWidth, windowHeight);
	}
	for (map[rand() % mapMax] = -1; 1; Sleep(Delay))
	{
		if (_kbhit())
		{
			cl = _getch();
			if (cl == ' ')break; //空格直接结束
			switch (cl)
			{
			case 'a':case 'A':if (c != 'd')c = 'a'; break;//判断与原方向是否冲突
			case 'd':case 'D':if (c != 'a')c = 'd'; break;
			case 's':case 'S':if (c != 'w')c = 's'; break;
			case 'w':case 'W':if (c != 's')c = 'w'; break;
			}
		}
		switch (c)
		{
		case 'a':hX -= hX > 0 ? 1 : 1 - mapCols; break;//如果越界,则从相对的墙出来
		case 'w':hY -= hY > 0 ? 1 : 1 - mapLines; break;
		case 'd':hX += hX < mapCols - 1 ? 1 : 1 - mapCols; break;
		case 's':hY += hY < mapLines - 1 ? 1 : 1 - mapLines; break;
		}
		if (map[hY * mapCols + hX] > 1) break; //碰到蛇身，直接结束
		if (map[hY * mapCols + hX] == -1) //碰到食物
		{
			len++;
			do i = rand() % mapMax;
			while (map[i]); //直到指定位置为空地
			map[i] = -1;
		}
		else //空地
			for (i = 0; i < mapMax; i++)
				if (map[i] > 0)map[i]--;//全体蛇身值-1
		map[hY * mapCols + hX] = len;
		SetConsoleCursorPosition(hOut, origin);
		for (i = 0; i < mapMax; i++)
		{
			printf(map[i] > 0 ? "■" : map[i] ? "●" : "  ");
			if (map[i])ShowWindow(screen[i], SW_SHOWDEFAULT);
			else ShowWindow(screen[i], SW_HIDE);
		}
	}
	Sleep(1000);
	free(map);
	free(screen);
}

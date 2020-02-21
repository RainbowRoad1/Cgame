#include<windows.h>
#include<conio.h>
#include<time.h>
#define width 180//长
#define height 180//宽
#define cols (1920 / width)//列（前面的数字和分辨率有关）
#define lines (1080 / height)//行
#define Max (cols * lines)//总数
#define Delay 200//延迟
void create(int* p, int Cols, int Lines, int Alive)//创建进程
{
	p[0] = Cols;
	p[1] = Lines;
	p[2] = Alive;
	system("start Screen.exe");//start dos命令来生成新进程,生成的.exe文件叫什么,后面就填什么
}
int main()
{
	char strMapName[6] = "Snake";//共享内存名称
	int* pBuf;//共享内存指针------0:列数; 1:行数; 2:长度; 3:方向动作;
	HANDLE hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, strMapName);//打开文件映射对象
	if (hMap == NULL)//主进程
	{
		system("mode con:cols=16 lines=2");//修改窗口大小
		srand((unsigned)time(0));//初始化随机数种子
		hMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 16, strMapName);//创建文件映射内核对象
		pBuf = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);//将文件映射对象映射到当前程序的地址空间
		int map[Max] = { 0 }, hX = 0, hY = 0, len = 4, c = 'd', i = 0;//这里跟之前的18行贪吃蛇差不多，这里不多描述
		i = rand() % Max, map[i] = -1;//生成一个食物
		create(pBuf, i % cols, i / cols, -1);//创建进程
		Sleep(100);//防止与新数据发生冲突
		while (1)//主循环
		{
			if (pBuf[3] == ' ')break;//空格键退出
			switch (pBuf[3])//判断输入动作
			{
			case 'a':case 'A':if (c != 'd')c = 'a'; break;//输入动作合理才改变方向
			case 'd':case 'D':if (c != 'a')c = 'd'; break;
			case 's':case 'S':if (c != 'w')c = 's'; break;
			case 'w':case 'W':if (c != 's')c = 'w'; break;
			}
			switch (c)//移动
			{
			case 'a':hX -= hX > 0 ? 1 : 1-cols; break;//如果越界,则从相对的墙出来
			case 'w':hY -= hY > 0 ? 1 : 1-lines; break;
			case 'd':hX += hX < cols - 1 ? 1 : 1-cols; break;
			case 's':hY += hY < lines - 1 ? 1 : 1-lines; break;
			}
			if (map[hY * cols + hX] > 1)break;//如果头坐标是蛇身,跳出,结束
			if (map[hY * cols + hX] == -1)//如果是食物
			{
				len++;//蛇身增加
				do i = rand() % Max;//循环生成
				while (map[i]);//直到生成的位置为空地为止,防止生成在蛇上
				map[i] = -1;//赋值
				create(pBuf, i % cols, i / cols, -1);//创建食物进程
				Sleep(100);//同样也需要延迟
			}
			else//剩下就只有空地了
				for (i = 0; i < Max; i++)
					if (map[i] > 0)map[i] -= 1;//全体值-1
			map[hY * cols + hX] = len;//头坐标赋值
			create(pBuf, hX, hY, len);//创建蛇身进程
			Sleep(Delay);//延迟
		}
		pBuf[2] = 0;//蛇长改为0,防止其他进程陷入死循环
	}
	else//子进程
	{
		pBuf = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);//将文件映射对象映射到当前程序的地址空间
		HWND hWnd = GetConsoleWindow();//获取控制台窗口句柄
		int i = 0, j = 0;
		SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_CAPTION);//隐藏标题栏
		MoveWindow(hWnd, pBuf[0] * width, pBuf[1] * height, width, height, 1);//移动窗口位置及大小
		if (pBuf[2] == -1)//食物
		{
			system("color fc");//改变窗口颜色
			j = 1;
			while (pBuf[2] && pBuf[2] < 0)Sleep(10);//直到生成新蛇身为止(如长度为0同样跳出防止死循环)
			i = pBuf[2];//记录当前蛇长
		}
		while (1)
		{
			if (_kbhit())pBuf[3] = _getch();//检测输入动作
			Sleep(10);//延迟
			if (j)
			{
				if (i != pBuf[2] || !pBuf[2])break;
			}
			else
			{
				if (pBuf[2] < 0)Sleep(100), i += 100;//如果有食物生成(会有延迟),则延迟对应时间
				else if (!pBuf[2] || clock() > pBuf[2] * Delay + i)break;//直到长度为0或存在时间超过长度*延迟时间,结束
			}
		}
	}
	UnmapViewOfFile(pBuf);//停止内存映射
	CloseHandle(hMap);//关闭一个内核对象
}

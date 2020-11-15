#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
char strMapName[6] = "Snake";//共享内存名称
void create(int x, int y, char* target, int type)//创建进程, 参数: 窗口坐标, 路径, 类型
{
	char str[64];//start命令缓存, 注意文件路径不要很长
	sprintf(str, "start %s %d %d %d", target, type, x, y);//生成新进程的命令
	//sprintf_s(str, 64, "start %s %d %d %d", target, type, x, y); //vs换成此行代码来避免4996号错误
	if (system(str))exit(0);//start dos命令来生成新进程, 现在不用担心命名问题了, 如果生成失败直接结束进程
}
int main(int argc, char** acgv)
{
	int* pBuf;//共享内存指针------0:长度; 1:方向动作; 2:地图列数; 3:地图行数; 4:延迟
	HANDLE hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, 0, strMapName);//打开文件映射对象
	if (hMap == NULL)//主进程
	{
		int width, height, cols, lines, delay;//窗口尺寸, 地图尺寸, 延迟
		int* map, hX = 0, hY = 0, c = 'd', i, Max, f, oldTime;//前7个参数可参考tiny版, f为食物位置, oldTime记录上次刷新时间
		cols = argc > 1 ? atoi(acgv[1]) : 10;//地图列数, 默认10
		lines = argc > 2 ? atoi(acgv[2]) : 6;//地图行数, 默认6
		delay = argc > 3 ? atoi(acgv[3]) : 200;//延迟, 默认200
		if (cols * lines * delay == 0)printf("Input error!"), _getch(), exit(0);//如果出现0值, 提示
		Max = cols * lines, width = GetSystemMetrics(0) / cols, height = GetSystemMetrics(1) / lines;//初始化部分参数
		hMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 20, strMapName);//创建文件映射内核对象
		pBuf = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);//将文件映射对象映射到当前程序的地址空间
		pBuf[0] = 4, pBuf[2] = width, pBuf[3] = height, pBuf[4] = delay;//全局变量(所有进程)
		srand((unsigned)time(0));//初始化随机数种子
		map = calloc(Max, 4), f = rand() % Max, map[f] = -1;//分配内存, 生成一个食物
		printf("width:%d, height:%d\ncols:%d, lines:%d\ndelay:%d\n", width, height, cols, lines, delay);//输出部分参数
		printf("Input to start..."), _getch(), oldTime = clock();//开始前按任意键开始
		create(f % cols, f / cols, acgv[0], 1);//创建食物进程
		while (1)//主循环
		{
			if (pBuf[1] == ' ')break;//空格键退出
			switch (pBuf[1])//判断输入动作
			{
			case 'a':case 'A':if (c != 'd')c = 'a'; break;//输入动作合理才改变方向
			case 'd':case 'D':if (c != 'a')c = 'd'; break;
			case 's':case 'S':if (c != 'w')c = 's'; break;
			case 'w':case 'W':if (c != 's')c = 'w'; break;
			}
			switch (c)//移动
			{
			case 'a':hX -= hX > 0 ? 1 : 1 - cols; break;//如果越界,则从相对的墙出来
			case 'w':hY -= hY > 0 ? 1 : 1 - lines; break;
			case 'd':hX += hX < cols - 1 ? 1 : 1 - cols; break;
			case 's':hY += hY < lines - 1 ? 1 : 1 - lines; break;
			}
			if (map[hY * cols + hX] > 1)break;//如果头坐标是蛇身,跳出,结束
			if (map[hY * cols + hX] == -1)//如果是食物
			{
				do f = rand() % Max;//循环生成
				while (map[f]);//直到生成的位置为空地为止,防止生成在蛇上
				++pBuf[0], map[f] = -1;//蛇身增加, 赋值
				create(f % cols, f / cols, acgv[0], 1);//创建食物进程
				Sleep(100);//同样也需要延迟
			}
			else for (i = 0; i < Max; i++)map[i] > 0 && --map[i];//剩下就只有空地了, 全体值-1
			map[hY * cols + hX] = pBuf[0], create(hX, hY, acgv[0], 0);//头坐标赋值并生成蛇身进程
			system("cls");//清屏, 下面输出部分参数
			printf("head(%d,%d)|len:%d\nfood(%d,%d)|move:%c", hX, hY, pBuf[0], f % cols, f / lines, c);
			while (oldTime + pBuf[4] > clock())if (Sleep(1), _kbhit())pBuf[1] = _getch();//延迟, 检测输入动作
			oldTime += pBuf[4];//进位
		}
		pBuf[0] = 0;//蛇长改为0,使其他进程结束循环
		Sleep(100);
	}
	else//子进程
	{
		HWND hWnd = GetConsoleWindow();//获取控制台窗口句柄
		int i = 0, j = 0;//i: 储存当前蛇长; j: 是否为食物的标志
		pBuf = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);//将文件映射对象映射到当前程序的地址空间
		//SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_CAPTION);//隐藏标题栏, 根据自己需要来使用
		MoveWindow(hWnd, atoi(acgv[2]) * pBuf[2], atoi(acgv[3]) * pBuf[3], pBuf[2], pBuf[3], 1);//移动窗口位置及大小
		atoi(acgv[1]) ? system("color a0"), i = pBuf[0], j = 1 : system("color cf"); //修改窗口颜色, 食物有额外操作
		system("cls");//清屏可防止部分黑框
		while (1)
		{
			if (_kbhit())pBuf[1] = _getch();//检测输入动作
			if (pBuf[0] == 0)break;//长度为0, 直接结束
			if (j && i != pBuf[0])break;//食物: 蛇长发生变化结束
			if (!j && clock() > pBuf[0] * pBuf[4])break;//超过一定时间(蛇长*延迟)则结束
			Sleep(10);//延迟
		}
	}
	UnmapViewOfFile(pBuf);//停止内存映射
	CloseHandle(hMap);//关闭一个内核对象
}

/*
用窗口玩贪吃蛇, 90行, 3951字符(包含注释);
ADSW移动, 吃到食物成长, 可穿墙, 吃到自己身体或按下空格键游戏结束;
运行前需要在主进程按下任意键(打印了部分参数, 方便确认命令行参数是否生效)

原理非常简单, 通过共享内存和命令行传参来实现进程间的通信
先判断共享内存名称是否存在, 没有则生成一个(主进程), 存在就生成子进程
主进程掌握全局, 不断生成子进程并进行一系列判定和更新蛇长(pBuf[0])
子进程达到一定条件则结束, 比如主进程结束(蛇长归零), 蛇长更新(食物), 存在时间过长(蛇身)
子进程不断生成持续获得输入焦点, 子进程还要将输入回馈给主进程(pBuf[1])

可使用命令行来修改参数, 解决改完参数又要重新编译的问题;
输入格式: ./target -cols -lines -delay (shell需要'./', cmd不需要)
target为程序路径, cols为地图列数, lines为地图行数, delay为延迟, 参数直接输入数字
例:
./Snake.exe 18 12 100
生成一个地图尺寸为18*12, 每轮循环延迟为100ms的游戏(这里使用了相对路径)
D:/Snake 15
生成一个地图尺寸为15*6, 每轮循环延迟为200ms的游戏(参数不够则使用默认值)

原来的代码逻辑有许多问题(最难受的是打开直接刷屏然后卡死)
现在已基本解决, 且运行更加流畅, 还方便修改参数

时不时会出现窗口尺寸变宽(这个我也不清楚原因, 代码逻辑上是没问题的)
文件路径不要太长, 太长会触发断言(或者其他情况), 可以拓展字符串的缓存解决

2020.11.15
	改正部分文本错误
2020.10.01
	*补充说明
	*修改大量代码(几乎重写了)
2020.2.21
	上传
*/

#include<windows.h>
#include<conio.h>
#include<stdio.h>
int main()
{
	int hX = 7, hY = 7, len = 4, i = 0, map[900] = { 0 };//头坐标，蛇长，循环变量，地图（-1:食物;0:空白;>0:蛇身）
	char c = 'd', cl = 'd', deaw[1801] = { 0 };//初始方向，输入缓存，绘制缓存
	system("mode con: cols=60 lines=30");//修改控制台窗口大小
	srand((unsigned)malloc(1));//初始化随机数种子
	for (map[rand() % 900] = -1; 1; Sleep(100))//生成食物,延时
	{
		if (_kbhit() && (cl = _getch()))//判断是否输入
			switch (cl)
			{
				case 'a':case 'A':if (c != 'd')c = 'a'; break;//判断与原方向是否冲突
				case 'd':case 'D':if (c != 'a')c = 'd'; break;
				case 's':case 'S':if (c != 'w')c = 's'; break;
				case 'w':case 'W':if (c != 's')c = 'w'; break;
			}
		switch (c)
		{
			case 'a':hX -= hX > 0  ? 1 : -29; break;//更新头坐标
			case 'd':hX += hX < 29 ? 1 : -29; break;
			case 's':hY += hY < 29 ? 1 : -29; break;
			case 'w':hY -= hY > 0  ? 1 : -29; break;
		}
		if (map[hY * 30 + hX] > 1)exit(!_getch());//判断是否吃到自己
		if (map[hY * 30 + hX] == -1)//判断是否吃到食物
		{
			len++;
			do i = rand() % 900;
			while (map[i]);//保证食物生成位置为空地
			map[i] = -1;
		}
		else for (i = 0; i < 900; i++)//全部蛇身值-1
			if (map[i] > 0)map[i] -= 1;
		map[hY * 30 + hX] = len;//蛇头赋值
		for (i = 0; i < 1800; i++)//更新绘制缓存
		{
			if (map[i / 2] == 0)deaw[i] = ' ';
			else if (map[i / 2] > 0)deaw[i] = (i % 2) ? ')' : '(';
			else deaw[i] = '0';
		}
		system("cls");//清屏
		printf(deaw);//打印
	}
}

/*
47行贪吃蛇, 1400字符(包括注释), 尽量写的容易理解;
ADSW移动, 吃到食物成长, 可穿墙, 吃到自己身体时游戏结束;
可自定义蛇头位置(hX, hY), 蛇长(len), 初始方向(c);
通过printf打印来避免闪屏, 不过还是光标定位更香...
本来想着这种版本每种游戏都写一遍, 到现在还是仅限于贪吃蛇(雾)
于2020.1.28上传, 2020.10.1补充说明

下面是之前的说明:

47行贪吃蛇，在18行贪吃蛇的基础上，减少闪烁 穿墙 吃蛇尾不死，代码书写基本规范，可读性还行
只要掌握数组和部分函数使用就可以做出来，萌新都能看的懂
用到的函数：
--windows.h:
system()控制台命令//mode改窗口大小cls清屏
srand()随机数种子
rand()随机数
Sleep()延时
exit()结束
malloc()分配内存//返回地址随机
--conio.h:
_kbhit()检测是否有键盘输入
_getch()获取一个字符
--stdio.h:
printf()输出//代替cprintf()貌似能去闪烁(???)
*/

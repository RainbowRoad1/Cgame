#include<windows.h>
#include<conio.h>
int main() {
    int hX = 0, hY = 0, len = 4, map[900] = { 0 }, c = 'd', cl = 'd', i = 0;
    srand((unsigned)malloc(!system("mode con:cols=60 lines=30")));
    for (map[rand() % 900] = -1; 1; Sleep(100)) {
        if (_kbhit() && (cl = _getch()) && cl < 97 ? (cl += 32) : 1)
            if (cl == 'a' && c != 'd' || cl == 'd' && c != 'a' ||
                cl == 'w' && c != 's' || cl == 's' && c != 'w')c = cl;
        if (c == 'a' && --hX < 0 || c == 'd' && ++hX == 30 ||
            c == 'w' && --hY < 0 || c == 's' && ++hY == 30)exit(0);
        if (map[hY * 30 + hX] && (map[hY * 30 + hX] > 0 ? exit(0), 1 : ++len))
            for (i = rand() % 900; map[i] || !(map[i] = -1); i = rand() % 900);
        else for (i = 0; i < 900; i++) map[i] > 0 ? map[i] -= 1 : 0;
        for (system("cls"), map[hY * 30 + hX] = len, i = 0; i < 900; i++)
            _cputs(map[i] > 0 ? "()" : map[i] ? "00" : "  ");
    }
}

/*
18行贪吃蛇, 969字符, 实现了简单的功能;
ADSW移动, 吃到食物成长, 吃到自己身体时或撞墙时游戏结束;
可自定义蛇头位置(hX, hY), 蛇长(len), 初始方向(c);
很多功能并不完善, 局限于当时的技术只能这样了...
现在都已经到14行了...
注意, 此版本吃蛇尾会仍会判定为蛇身, 后续版本与此版本都相反
额外提及几点:
1. malloc()的返回值被忽略, 会不会造成内存泄漏?
这个其实没什么好担心的, 又不是在循环里执行, 程序结束都释放了
2. 此处的windows.h可换成stdlib.h
Sleep()换成_sleep()就行, 在vs会出现4996号错误, 屏蔽就行了
屏蔽4996号错误可使用下面的代码:
#pragma warning(disable:4996)
3. 关于移植到其他平台
conio.h并不属于标准库, 输出可以用stdio.h里的printf()
输入可能麻烦点, getch()和kbhit()可以自己用其他函数来实现
这方面网上有很多方法, 这里仅能提供一个游戏整体的思路

于2020.1.28上传, 2020.10.1补充说明, 并增加了一些空格使其规范
*/
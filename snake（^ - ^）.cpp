#include <iostream>
#include <windows.h>
#include <cstdlib>   //定义杂项函数及内存分配函数
#include <cstdio>   //定义输入／输出函数
#include <string>   //字符串处理
#include <conio.h>  //主要是一些用户通过按键盘产生的对应操作
#include <ctime>   //定义关于时间的函数

using namespace std;

int snake[1000][2];  //蛇每一节x,y坐标
int length = 3;
int food[2] = {20,15}; //食物x,y坐标
int a = 1;  //x坐标变化
int b = 0;  //y坐标变化
int s = 1;  //主函数循环
int speed = 500;  //间隔时间（速度） 时间越小 速度越大
int score = 0;
int level = 1;

void start();
void hide();  //隐藏光标
void gotoxy(short x, short y);  //gotoxy () 将光标移动到指定位置 
void drawWall();
void drawSnake();
void changeSnake();
void drawFood();
void changeDirection();
void eatFood();
void gameOver();
void end();

int main()
{
	start();
	hide();
	drawWall();
	drawSnake();
	drawFood();
	while(s)  //进入主函数循环
	{
		changeDirection();
		changeSnake();
		eatFood();
		gameOver();
	}
	end();
	return 0;
}

void hide()    //隐藏光标 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);
}

void gotoxy(short x, short y)  ////gotoxy () 将光标移动到指定位置  
{
    COORD position = { x, y };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, position);
}

void start()   
{
	gotoxy(20, 10);
    cout << "welcome to snake （^ - ^）";
	gotoxy(20, 20);
    cout << "Press enter to start your game （^ - ^） ";
	cin.get();   //使用get()函数 简单的暂停屏幕 直到按下回车键 避免直接进行下面的清屏操作 
	system("cls");  //清屏 
}

void drawWall()  //打印墙和初始提示界面 
{
    for (int i=1;i<=20;i++)
    {
        gotoxy(0, i);
        cout << "#";
        gotoxy(40, i);
        cout << "#";
    }
	for (int l=0;l<=40;l++)
    {
		gotoxy(l, 0);
        cout << "#";
        gotoxy(l, 20);
        cout << "#";
    }
    gotoxy(50, 10);
    cout << "press w,s,a,d to change direction.";
    gotoxy(50,14);
	cout << "score: " << score << endl;
	gotoxy(50,16);
	cout << "level: " << level;
	gotoxy(50, 18);
    cout << "press Space to stop ,press Enter to continue";
}

void drawSnake()  //初始化蛇
{
	snake[0][0] = 10;
    snake[0][1] = 10;
	snake[1][0] = 9;
    snake[1][1] = 10;
	snake[2][0] = 8;
    snake[2][1] =10;
	gotoxy(snake[0][0],snake[0][1]);  //@表示蛇头 
	cout << "@";
    gotoxy(snake[1][0], snake[1][1]);  //*表示蛇身
    cout << "*";
	gotoxy(snake[2][0], snake[2][1]);
    cout << "*";
}

void drawFood()  //打印食物
{
	gotoxy(food[0], food[1]);
	cout <<"$";  //$表示食物 
}
void changeFood()  //改变食物坐标
{
	int f = 1;
	while(f)   //进入一个函数循环
	{
		srand((int)time( NULL ));
		food[0] = rand() % 39 + 1;
		srand((int)time(0));
		food[1] = rand() % 19 + 1;
		for (int i = length-1; i > 0; i--)
		{
			if(snake[i][0] == food[0] && snake[i][1] == food[1])
			{
				f = 1;
				break;
			}
			else
				f = 0;
		}
	}
	drawFood();
}

void eatFood()  //蛇吃食物
{
	if(snake[0][0] == food[0] && snake[0][1] == food[1])
	{
		gotoxy(snake[length-1][0],snake[length-1][1]);  //加分
		cout << "*";
		length += 1;    //加长度 
		score += 1;
		gotoxy(50,14);
		cout << "score: " << score << endl;
		if(score!= 0 && score%5 == 0)  //加等级
		{
			level += 1;
			if( speed != 100)  //游戏难度升级 加速
			speed -= 100;
			gotoxy(50,16);
			cout << "level: " << level;
		}
		changeFood();
		
	}
	gotoxy(0,0);
	cout << "#";
}

void changeDirection()  //键盘控制改变行进方向
{
	if (kbhit()!=0)  //检测按键  如果有按键按下 返回对应值 否则返回零
    {
        char ch = getch();  //通过按键盘产生对应操作 一次只能读取一个字符
        switch (ch)
        {
        case 'w':  //向上 x坐标不变 y坐标改变 
		case 'W':
			if(b == 0)  //防止反方向改变，下同
			{
				a = 0;
				b = -1;
			}
            break;
        case 's':
		case 'S':
			if(b == 0)
			{
				a = 0;
				b = 1;
			}
            break;
        case 'a':
		case 'A':
			if(a == 0)
			{
				a = -1;
				b = 0;
			}
            break;
        case 'd':
		case 'D':
			if(a == 0)
			{
				a = 1;
				b = 0;
			}
            break;
        case ' ':
            cin.get();
            break;
        default:
            break;
        }
   }
}

void changeSnake()  //改变蛇位置
{
	gotoxy(snake[length-1][0],snake[length-1][1]);
	cout << " ";  //清除尾巴
	for (int i = length-1; i > 0; i--)  //改变身体坐标
	{
		for (int j = 0; j < 2; j++)
		{
			snake[i][j] = snake[i - 1][j];
		}
	}
	snake[0][0] += a;
	snake[0][1] += b;  //改变蛇头坐标
	gotoxy(snake[0][0],snake[0][1]);
	cout << "@";
	gotoxy(snake[1][0],snake[1][1]);
	cout << "*";
	Sleep(speed);  //Sleep() 函数 使计算机程序进入休眠 控制时间 从而控制蛇的前进速度 
}

void gameOver()  //游戏结束
{
	if(snake[0][0] == 0 || snake[0][0] == 40 || snake[0][1] == 0 || snake[0][1] == 20)  //撞墙
	{
		s = 0;
		system("cls");
	}
	for (int i = length-1; i > 0; i--)  //蛇头碰到蛇身 
	{
		if(snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1])
		{
		s = 0;
		system("cls");
		}
	}
}

void end()
{
	gotoxy(20, 10);
	cout << "Game over （* - *）" << endl;
	gotoxy(20, 12);
	cout << "your score: " << score << endl;
	gotoxy(20, 14);
	cout << "Welcome to play again （^ - ^）";
	gotoxy(20, 20);
	cin.get();
}

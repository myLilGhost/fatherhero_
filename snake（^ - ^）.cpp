#include <iostream>
#include <windows.h>
#include <cstdlib>   //������������ڴ���亯��
#include <cstdio>   //�������룯�������
#include <string>   //�ַ�������
#include <conio.h>  //��Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ����
#include <ctime>   //�������ʱ��ĺ���

using namespace std;

int snake[1000][2];  //��ÿһ��x,y����
int length = 3;
int food[2] = {20,15}; //ʳ��x,y����
int a = 1;  //x����仯
int b = 0;  //y����仯
int s = 1;  //������ѭ��
int speed = 500;  //���ʱ�䣨�ٶȣ� ʱ��ԽС �ٶ�Խ��
int score = 0;
int level = 1;

void start();
void hide();  //���ع��
void gotoxy(short x, short y);  //gotoxy () ������ƶ���ָ��λ�� 
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
	while(s)  //����������ѭ��
	{
		changeDirection();
		changeSnake();
		eatFood();
		gameOver();
	}
	end();
	return 0;
}

void hide()    //���ع�� 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);
}

void gotoxy(short x, short y)  ////gotoxy () ������ƶ���ָ��λ��  
{
    COORD position = { x, y };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, position);
}

void start()   
{
	gotoxy(20, 10);
    cout << "welcome to snake ��^ - ^��";
	gotoxy(20, 20);
    cout << "Press enter to start your game ��^ - ^�� ";
	cin.get();   //ʹ��get()���� �򵥵���ͣ��Ļ ֱ�����»س��� ����ֱ�ӽ���������������� 
	system("cls");  //���� 
}

void drawWall()  //��ӡǽ�ͳ�ʼ��ʾ���� 
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

void drawSnake()  //��ʼ����
{
	snake[0][0] = 10;
    snake[0][1] = 10;
	snake[1][0] = 9;
    snake[1][1] = 10;
	snake[2][0] = 8;
    snake[2][1] =10;
	gotoxy(snake[0][0],snake[0][1]);  //@��ʾ��ͷ 
	cout << "@";
    gotoxy(snake[1][0], snake[1][1]);  //*��ʾ����
    cout << "*";
	gotoxy(snake[2][0], snake[2][1]);
    cout << "*";
}

void drawFood()  //��ӡʳ��
{
	gotoxy(food[0], food[1]);
	cout <<"$";  //$��ʾʳ�� 
}
void changeFood()  //�ı�ʳ������
{
	int f = 1;
	while(f)   //����һ������ѭ��
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

void eatFood()  //�߳�ʳ��
{
	if(snake[0][0] == food[0] && snake[0][1] == food[1])
	{
		gotoxy(snake[length-1][0],snake[length-1][1]);  //�ӷ�
		cout << "*";
		length += 1;    //�ӳ��� 
		score += 1;
		gotoxy(50,14);
		cout << "score: " << score << endl;
		if(score!= 0 && score%5 == 0)  //�ӵȼ�
		{
			level += 1;
			if( speed != 100)  //��Ϸ�Ѷ����� ����
			speed -= 100;
			gotoxy(50,16);
			cout << "level: " << level;
		}
		changeFood();
		
	}
	gotoxy(0,0);
	cout << "#";
}

void changeDirection()  //���̿��Ƹı��н�����
{
	if (kbhit()!=0)  //��ⰴ��  ����а������� ���ض�Ӧֵ ���򷵻���
    {
        char ch = getch();  //ͨ�������̲�����Ӧ���� һ��ֻ�ܶ�ȡһ���ַ�
        switch (ch)
        {
        case 'w':  //���� x���겻�� y����ı� 
		case 'W':
			if(b == 0)  //��ֹ������ı䣬��ͬ
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

void changeSnake()  //�ı���λ��
{
	gotoxy(snake[length-1][0],snake[length-1][1]);
	cout << " ";  //���β��
	for (int i = length-1; i > 0; i--)  //�ı���������
	{
		for (int j = 0; j < 2; j++)
		{
			snake[i][j] = snake[i - 1][j];
		}
	}
	snake[0][0] += a;
	snake[0][1] += b;  //�ı���ͷ����
	gotoxy(snake[0][0],snake[0][1]);
	cout << "@";
	gotoxy(snake[1][0],snake[1][1]);
	cout << "*";
	Sleep(speed);  //Sleep() ���� ʹ���������������� ����ʱ�� �Ӷ������ߵ�ǰ���ٶ� 
}

void gameOver()  //��Ϸ����
{
	if(snake[0][0] == 0 || snake[0][0] == 40 || snake[0][1] == 0 || snake[0][1] == 20)  //ײǽ
	{
		s = 0;
		system("cls");
	}
	for (int i = length-1; i > 0; i--)  //��ͷ�������� 
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
	cout << "Game over ��* - *��" << endl;
	gotoxy(20, 12);
	cout << "your score: " << score << endl;
	gotoxy(20, 14);
	cout << "Welcome to play again ��^ - ^��";
	gotoxy(20, 20);
	cin.get();
}

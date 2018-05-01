#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "console.h"

using namespace std;

//Tham khảo trên mạng
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void SetBGColor(WORD color)
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

WORD wAttributes = screen_buffer_info.wAttributes;
color &= 0x000f;
color <<= 4;
wAttributes &= 0xff0f;
wAttributes |= color;

SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr()
{
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
HANDLE hConsoleOut;
COORD Home = {0,0};
DWORD dummy;

hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
csbiInfo.dwCursorPosition.X = 0;
csbiInfo.dwCursorPosition.Y = 0;
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void ToMau(int x, int y, char *a, int color)
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

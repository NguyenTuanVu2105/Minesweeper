#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>

using namespace std;

void resizeConsole(int width, int height);
void SetBGColor(WORD color);
void clrscr();  //Xoa man hinh
void textcolor(int x); //Đổi màu chữ
void gotoxy(int x,int y); //Di chuyển đến vị trí x,y
void ToMau(int x, int y, char *a, int color); //Đổi màu Text

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
#define MAX 10
#define mine (char)235
#define hoicham (char)15
#define UP 'H'
#define DOWN 'P'
#define LEFT 'K'
#define RIGHT 'M'
#define ENTER (char)13
#define FLAG 'R'
#define DELETE 'S'
#define flag char(158)
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void random(char stack[][MAX])
{
	srand(time(0));
	int i,j,count=0;
	for (i=0;i<MAX;i++)
		for (j=0;j<MAX;j++)
		{
			stack[i][j] = rand()%5;
            if (stack[i][j] == 0)
                {
                    stack[i][j] = mine;
                }
				else stack[i][j] = '.';
		}
}
int minecount(char stack[][MAX],int hang,int cot)
{
	int i,j,dem=0;
	for (i=hang-1;i<=hang+1;i++)
		for (j=cot-1;j<=cot+1;j++)
			if (i>=0 && i<MAX && j>=0 && j<MAX && stack[i][j] == mine)
			 dem++;
	return dem;
}
void createnumber(char stack[][MAX])
{
	int i,j;
	for (i=0;i<MAX;i++)
		for (j=0;j<MAX;j++)
			if (stack[i][j] == '.') stack[i][j] = (char)(minecount(stack,i,j)+48);
}

void nhap_toa_do(int &x,int &y)
{
    cout << endl << "Moi ban nhap toa do can mo : ";
    cin >> x >> y;
}
void draw_game(char stack_begin[][MAX])
{
    int i,j;
    for (i=0;i<MAX;i++)
    {
        for (j=0;j<MAX;j++) cout << stack_begin[i][j] << " ";
        cout << endl;
    }
}
void open_square(char stack_begin[][MAX],char stack_end[][MAX],const int &x,const int &y)
{
    stack_begin[x][y] = stack_end[x][y];
    draw_game(stack_begin);
}
void draw_begin()
{
    int i,j;
    for (i=0;i<MAX;i++)
        {
            for (j=0;j<MAX;j++)
                cout << hoicham << " ";
            cout << endl;
        }
}
void move(char stack_end[][MAX],int &x,int &y,bool &end)
{
    char c=_getch();
    switch(c)
    {
    case LEFT:
        if (x!=1) x-=2;
        break;
    case RIGHT:
        if (x!=MAX*2-1) x+=2;
        break;
    case UP:
        if (y!=1) y--;
        break;
    case DOWN:
        if (y!=MAX) y++;
        break;
    case ENTER:
        cout << stack_end[x/2][y-1];
        if (stack_end[x/2][y-1] == mine)
            {
                end = false;
                gotoxy(1,15);
            }
        break;
    case FLAG:
        cout << flag;
        break;
    case DELETE:
        cout << hoicham;
        break;
    default : cout << "";
    }
}
int main()
{
	char stack_end[MAX][MAX];
	char stack_begin[MAX][MAX];
	random(stack_end);
	createnumber(stack_end);
    int x=1,y=1;
    draw_begin();
    bool end=true;
    while(end)
    {
    gotoxy(x,y);
    move(stack_end,x,y,end);
    }
    return 0;
}

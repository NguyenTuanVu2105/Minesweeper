#include"ColorDisplay.h"
#include "board.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "console.h"
#include "game.h"
#include "draw.h"
#define NOTENTER 'v'

int main()
{
    char PlayerChoose;char press = ' ';
    do
    {
    clrscr();
    gotoxy(1,1);
    StartGame(PlayerChoose); //draw.h
    switch (PlayerChoose)
    {
        case NEWGAME:
            clrscr();
            gotoxy(1,1);
            char LevelChoose;
            NewGame(LevelChoose);
            if (LevelChoose==EASY)
            {
                game Game(10,10,10); //Khởi tạo game easy 10x10 với 10 quả mìn
                Game.Move();
            }
            if (LevelChoose==MEDIUM)
            {
                game Game(20,12,12); //Khởi tạo game medium 12x12 với 20 quả mìn
                Game.Move();
            }
            if (LevelChoose==HARD)
            {
                game Game(50,15,15); //Khởi tạo game Hard 15x15 với 50 quả mìn
                Game.Move();
            }
            press = ENTER;
            break;
        case INTRODUCE:
            clrscr();
            gotoxy(1,1);
            Introduce();
            do
            {
                press = getch();
            }
            while (press!=ENTER);
            break;
        case EXIT:
            press = NOTENTER;
    }
    } while (press == ENTER);
}

#ifndef _GAME_H_INCLUDED
#define _GAME_H_INCLUDED

#include "draw.h"
#include "board.h"
#include "console.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER (char)13
#define SPACE 5

using namespace std;
class game
{
    public:
        game(int mines, int xsize, int ysize);
        ~game();
        void Move();
    private:
        int Xsize;
        int Ysize;
        int Mines;
        bool GameWin(board &bd);
        bool GameLose(board &bd, int x, int y);

};

#endif


#ifndef _BOARD_H_INCLUDED
#define _BOARD_H_INCLUDED

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "ColorDisplay.h"
#include <iostream>
#include "ColorDisplay.h"
#include <cstdlib>
#define NOTOPEN '.'
#define EMPTY '0'
#define MINE 'O'
#define FLAG 'F'
#define POINT 'c'
#define LEFT 1
#define RIGHT 2
#define DOWN 3
#define UP 4

class board
{
    public:
        board(int mines, int xsize, int ysize);
        ~board();
        char showData(int row, int col);
        void drawData(ColorDisplay &cd, int row, int col);  // In 1 ô của bảng
        void drawEmpty(ColorDisplay &cd, int row, int col);  // Xử lý trường hợp gặp ô trống
        void addPoint(int row,int col);  // Đặt vị trí cho con trỏ di chuyển
        void deletePoint(int row,int col);  // Hủy vị trí đặt con trỏ di chuyển
        void drawAll(ColorDisplay &cd);
        void reveal(ColorDisplay &cd,int row,int col);  // Mở 1 ô
        int countCellNotOpen();
    private:
        char temp;  //Bien tam cho display cua con tro
        char **display;
        char **data;
        int Xsize;
        int Ysize;
        void addToMineNumber(int row,int col); // Thêm số Mìn xung quanh vào 1 ô
};

#endif

#include "board.h"

board :: board(int mines, int xsize, int ysize)
{
    // Khoi tao gia tri
    Xsize = xsize;
    Ysize = ysize;
    temp =  ' ';

    // Cap phat vung nho cho data va display
    data = new char*[Xsize];
    display = new char*[Xsize];
    for (int i=0; i<Xsize; i++)
    {
        data[i] = new char[Ysize];
        display[i] = new char[Ysize];
    }

    // Khoi tao data và display
    for (int i=0; i<Xsize; i++)
        for (int j=0; j<Ysize; j++)
    {
        data[i][j] = '0';
        display[i][j] = NOTOPEN;
    }

    // Tao du lieu cho bang
    int row ,col ;
    srand(time(0));
    while (mines!=0)
    {
    do
    {
        row = rand() % Xsize;
        col = rand() % Ysize;
    } while (data[row][col] == MINE);
    data[row][col] = MINE;
    addToMineNumber(row,col);
    mines --;
    }

}

board :: ~board()
{
    for (int i=0; i<Xsize; i++)
    {
        delete[] data[i];
        delete[] display[i];
    }
    delete[] data;
    delete[] display;
}

void board :: addToMineNumber(int row, int col)
{
        for (int i = row-1; i<=row+1; i++)
            for (int j = col-1; j<=col+1; j++)
            {
                if (i>=0 && i < Xsize && j>=0 && j < Ysize && data[i][j]!=MINE)
                {
                    data[i][j]++;
                }
            }

}

void board :: drawData(ColorDisplay &cd, int row, int col)
{
    Image block(3,6);
    short color;
    char ch;
    switch (display[row][col])
    {
        case NOTOPEN:
            color = YELLOW;
            ch = ' ';
            break;
        case POINT:
            color = GREEN;
            if (temp == NOTOPEN || temp == EMPTY) ch=' ';
            else ch = temp;
            break;
        case MINE:
            color = RED;
            ch = 'O';
            break;
        case EMPTY:
            color = AQUA;
            ch = ' ';
            break;
        default:
            color = WHITE;
            ch = display[row][col];
    }
    fillBlock(block,color,ch);  //colordisplay.h
    cd.displayImage(block,{7*row,4*col});
}

void board :: drawEmpty(ColorDisplay &cd, int row, int col)
{
    if (display[row][col] != POINT)
        {
            display[row][col] = data[row][col];
        }
    else temp = data[row][col];
    drawData(cd,row,col);
    if (data[row][col] == '0')
    {
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++)
        {
            if (i!=0 || j!=0)
                if (row + i >= 0 && row + i < Xsize && col + j >=0 && col + j < Ysize)
                    if (display[row+i][col+j] == NOTOPEN)
                    {
                        drawEmpty(cd,row+i,col+j);
                    }
        }
    }
}

char board :: showData(int row, int col)
{
    return data[row][col];
}

void board :: addPoint(int row, int col)
{
    temp = display[row][col];
    display[row][col] = POINT;
}

void board :: deletePoint(int row, int col)
{
    display[row][col] = temp;
}

void board :: drawAll(ColorDisplay &cd)
{
    for (int i = 0; i<Xsize ; i++)
        for (int j=0; j<Ysize; j++)
    {
        drawData(cd,i,j);
    }
}

void board :: reveal(ColorDisplay &cd,int row, int col)
{
    if (temp == NOTOPEN)
        if (data[row][col] == '0')
        {
            drawEmpty(cd,row,col);
            display[row][col] = POINT;
            drawData(cd,row,col);
        }
        else
        {
            temp = data[row][col];
            drawData(cd,row,col);
        }
}

int board :: countCellNotOpen()
{
    int res = 0;
    for (int i=0; i<Xsize; i++)
        for (int j=0; j<Ysize; j++)
    {
        if (display[i][j] == NOTOPEN) res++;
        else if (display[i][j] == POINT && temp == NOTOPEN) res++;
    }
    return res;
}


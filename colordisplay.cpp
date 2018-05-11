#include <iostream>
#include <windows.h>
#include "ColorDisplay.h"

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

//Tham khảo
ColorDisplay::ColorDisplay( short _xScreeSize , short _yScreenSize , COORD _origin )
{
    outConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    origin = _origin;
    xScreenSize = _xScreeSize;
    yScreenSize = _yScreenSize;
}

void ColorDisplay::setColorCharacterAtPosition( const ColorCharacter & colorchar , const COORD & position)
{
    DWORD garbage = 0;
    FillConsoleOutputCharacter(outConsole, colorchar.character, 1, position, &garbage);
    FillConsoleOutputAttribute(outConsole, colorchar.color, 1, position, &garbage);
}

void ColorDisplay::setColorCharacterAtPosition( const ColorCharacter & colorchar , short xPosition , short yPosition )
{
    COORD position = { xPosition , yPosition };
    setColorCharacterAtPosition(colorchar, position);
}

void ColorDisplay::resetDisplay()
{
    DWORD garbage = 0;
    COORD pos;
    ColorCharacter cc; cc.color = BRIGHT_WHITE;

    pos.X = origin.X; pos.Y = origin.Y - 1; cc.character = 196;
    FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
    FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);

    pos.X = origin.X - 1; pos.Y = origin.Y - 1; cc.character = 218;
    setColorCharacterAtPosition(cc, pos);

    pos.X = origin.X + xScreenSize; pos.Y = origin.Y - 1; cc.character = 191;
    setColorCharacterAtPosition(cc, pos);

    pos.X = origin.X; pos.Y = origin.Y + yScreenSize; cc.character = 196;
    FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
    FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);

    pos.X = origin.X - 1; pos.Y = origin.Y + yScreenSize; cc.character = 192;
    setColorCharacterAtPosition(cc, pos);

    pos.X = origin.X + xScreenSize; pos.Y = origin.Y + yScreenSize; cc.character = 217;
    setColorCharacterAtPosition(cc, pos);

    cc.character = 179;
    short yPosScreen = yScreenSize + origin.Y;
    for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
    {
        pos.X = origin.X - 1;
        setColorCharacterAtPosition(cc, pos);
        pos.X = origin.X + xScreenSize;
        setColorCharacterAtPosition(cc, pos);
    }
    pos.X = origin.X; cc.character = ' '; cc.color = GRAY*16;
    for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
    {
        FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
        FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);
    }
}

void ColorDisplay::displayImage( const Image & img, const COORD & position )
{
    COORD pos;
    pos.Y = position.Y + origin.Y;
    for (unsigned short row = 0; row < img.image.size(); row++, pos.Y++)
    {
        pos.X = position.X + origin.X;
        for (unsigned short col = 0; col < img.image[row].size(); col++, pos.X++)
        {
            setColorCharacterAtPosition(img.image[row][col], pos);
        }
    }

}

void ColorDisplay::deleteDisplay()
{
    DWORD garbage = 0;
    COORD pos;
    ColorCharacter cc; cc.color = BLACK;

    pos.X = origin.X; pos.Y = origin.Y - 1; cc.character = 196;
    FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
    FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);

    pos.X = origin.X - 1; pos.Y = origin.Y - 1; cc.character = 218;
    setColorCharacterAtPosition(cc, pos);

    pos.X = origin.X + xScreenSize; pos.Y = origin.Y - 1; cc.character = 191;
    setColorCharacterAtPosition(cc, pos);

    pos.X = origin.X; pos.Y = origin.Y + yScreenSize; cc.character = 196;
    FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
    FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);

    pos.X = origin.X - 1; pos.Y = origin.Y + yScreenSize; cc.character = 192;
    setColorCharacterAtPosition(cc, pos);

    pos.X = origin.X + xScreenSize; pos.Y = origin.Y + yScreenSize; cc.character = 217;
    setColorCharacterAtPosition(cc, pos);

    cc.character = 179;
    short yPosScreen = yScreenSize + origin.Y;
    for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
    {
        pos.X = origin.X - 1;
        setColorCharacterAtPosition(cc, pos);
        pos.X = origin.X + xScreenSize;
        setColorCharacterAtPosition(cc, pos);
    }
    pos.X = origin.X; cc.character = ' '; cc.color = BLACK;
    for (pos.Y = origin.Y; pos.Y < yPosScreen; pos.Y++)
    {
        FillConsoleOutputCharacter(outConsole, cc.character, xScreenSize, pos, &garbage);
        FillConsoleOutputAttribute(outConsole, cc.color, xScreenSize, pos, &garbage);
    }
}
void fillBlock(Image &block,short color,char ch)
{
    ColorCharacter cc;
    cc.character = ' ';
    cc.color = color * 16;
    ColorCharacter cc1 = cc;
    cc1.character = ch;
    int i,j;
    for (i=0;i<3;i++)
        for (j=0;j<6;j++)
        {
        if (i == 1 && j == 2) block.image[i][j] = cc1;
        else block.image[i][j] = cc;
        }
}

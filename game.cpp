#include "game.h"


game :: game(int mines, int xsize, int ysize)
{
    Mines = mines;
    Xsize = xsize;
    Ysize = ysize;
}
game :: ~game()
{
    Mines = 0;
    Xsize = 0;
    Ysize = 0;
}
void game :: Move()
{
    //tao 1 ColorDisplay
    ColorDisplay cd(Xsize*7-1,Ysize*4-1,{1,1});
    cd.resetDisplay();

    //tạo 1 board và fill màu cho từng ô
    board bd(Mines,Xsize,Ysize);
    bd.drawAll(cd);

    //Khởi tạo con trỏ di chuyển
    int x=0,y=0;
    bd.addPoint(x,y);
    bd.drawData(cd,x,y);

    //Di chuyen
    bool _end = false;
    do
    {
    char key = getch();
    switch(key){
        //Di chuyen con tro
        case UP:
            if (y > 0)
            {
            bd.deletePoint(x,y);
            bd.drawData(cd,x,y);
            y--;
            bd.addPoint(x,y);
            bd.drawData(cd,x,y);
            }
            break;
        case DOWN:
            if (y<Ysize-1)
            {
            bd.deletePoint(x,y);
            bd.drawData(cd,x,y);
            y++;
            bd.addPoint(x,y);
            bd.drawData(cd,x,y);
            }
			break;
        case LEFT:
            if (x>0)
            {
            bd.deletePoint(x,y);
            bd.drawData(cd,x,y);
            x--;
            bd.addPoint(x,y);
            bd.drawData(cd,x,y);
            }
            break;
        case RIGHT:
            if (x < Xsize-1)
            {
            bd.deletePoint(x,y);
            bd.drawData(cd,x,y);
            x++;
            bd.addPoint(x,y);
            bd.drawData(cd,x,y);
            }
            break;

        //Mở ô
        case ENTER:
            bd.reveal(cd,x,y);
            bd.drawData(cd,x,y);

            //Kiểm tra điều kiện end game
            if (GameWin(bd) || GameLose(bd,x,y) ) _end = true;

            if (GameLose(bd,x,y))
            {
                bd.deletePoint(x,y);
                bd.drawData(cd,x,y);
                Sleep(500);
                cd.deleteDisplay();
                Defeat(); //draw.h
            }

            else if (GameWin(bd))
            {
                Sleep(500);
                cd.deleteDisplay();
                Victory(); //draw.h
            }
		}
    } while (!_end);
}
bool game :: GameWin(board &bd)
{
    return (bd.countCellNotOpen() == Mines); //Win khi chi con lại toàn mìn
}
bool game :: GameLose(board &bd, int x, int y)
{
    return (bd.showData(x,y) == MINE); //Lose khi mo phải mìn
}






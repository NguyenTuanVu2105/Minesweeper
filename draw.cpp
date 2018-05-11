#include "draw.h"

void StartGame(char &MenuChoose)
{
    clrscr();
    gotoxy(1,1);
    cout << "\t*       *   * * * *   *       *   *     *\n"
         << "\t* *   * *   *         * *     *   *     *\n"
         << "\t*   *   *   * * * *   *   *   *   *     *\n"
         << "\t*       *   *         *     * *   *     *\n"
         << "\t*       *   * * * *   *       *   * * * *\n"
         << "\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                   1. NEW GAME                         o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                   2. INTRODUCE                        o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                   3. EXIT                             o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
         << "\n\nPress Your Choosen (1 - 3): ";
    cin >> MenuChoose;
    while (MenuChoose!=NEWGAME && MenuChoose!=INTRODUCE && MenuChoose!=EXIT)
    {
        cout << "\nThe choosen is not avaiable.\n\n"
             << "Press Your Choosen : ";
        cin >> MenuChoose;
    }
}

void NewGame(char &LevelChoose)
{
    cout << "\t*       *   * * * *   *       *   *     *\n"
         << "\t* *   * *   *         * *     *   *     *\n"
         << "\t*   *   *   * * * *   *   *   *   *     *\n"
         << "\t*       *   *         *     * *   *     *\n"
         << "\t*       *   * * * *   *       *   * * * *\n"
         << "\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                   1. EASY                             o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                   2. MEDIUM                           o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                   3. HARD                             o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
         << "\n\nChoose the level (1 - 3) : ";
    cin >> LevelChoose;
    while (LevelChoose!=EASY && LevelChoose!=MEDIUM && LevelChoose!=HARD)
    {
        cout << "\nThe choosen is not avaiable.\n\n"
             << "Press Your Choosen : ";
        cin >> LevelChoose;
    }
}

void Introduce()
{
    cout << "\t*       *   * * * *   *       *   *     *\n"
         << "\t* *   * *   *         * *     *   *     *\n"
         << "\t*   *   *   * * * *   *   *   *   *     *\n"
         << "\t*       *   *         *     * *   *     *\n"
         << "\t*       *   * * * *   *       *   * * * *\n"
         << "\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
         << "\no                                                       o"
         << "\no     Press UP,DOWN,LEFT,RIGHT to move game.            o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no     Press ENTER to reveal the cell.                   o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no     If openned cell is MINE, Game End.                o"
         << "\no                                                       o"
         << "\no                                                       o"
         << "\no     A Number display the Number of Mine around it.    o"
         << "\no                                                       o"
         << "\nooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"
         << "\n\nPress ENTER to return.";
}

void Victory()
{
    gotoxy(1,1);
    textcolor(BLUE);
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\t\t*                *   *     * * * *    * * * * * * *    * * * * *     * * * * *    *         *  \t\t\t\t\t\n"
         << "\t\t\t\t *              *    *    *       *         *         *         *    *        *    *       *   \t\t\t\t\t\n"
         << "\t\t\t\t  *            *     *   *                  *        *           *   *        *     *     *    \t\t\t\t\t\n"
         << "\t\t\t\t   *          *      *   *                  *        *           *   *       *       *   *     \t\t\t\t\t\n"
         << "\t\t\t\t    *        *       *   *                  *        *           *   * * * *          * *      \t\t\t\t\t\n"
         << "\t\t\t\t     *      *        *   *                  *        *           *   *       *         *       \t\t\t\t\t\n"
         << "\t\t\t\t      *    *         *   *                  *        *           *   *        *        *       \t\t\t\t\t\n"
         << "\t\t\t\t       *  *          *    *       *         *         *         *    *         *       *       \t\t\t\t\t\n"
         << "\t\t\t\t        **           *     * * * *          *          * * * * *     *          *      *       \t\t\t\t\t\n";
    textcolor(WHITE);
    cout << "Press to back to Menu....";
    getch();
}

void Defeat()
{
    gotoxy(1,1);
    textcolor(RED);
    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\t\t* * * *     * * * * *   * * * * *   * * * * *           *        * * * * * * *\t\t\t\t\t\n"
         << "\t\t\t\t*      *    *           *           *                  * *             *      \t\t\t\t\t\n"
         << "\t\t\t\t*       *   *           *           *                 *   *            *      \t\t\t\t\t\n"
         << "\t\t\t\t*       *   *           *           *                *     *           *      \t\t\t\t\t\n"
         << "\t\t\t\t*       *   * * * * *   * * * * *   * * * * *       * * * * *          *      \t\t\t\t\t\n"
         << "\t\t\t\t*       *   *           *           *              *         *         *      \t\t\t\t\t\n"
         << "\t\t\t\t*       *   *           *           *             *           *        *      \t\t\t\t\t\n"
         << "\t\t\t\t*      *    *           *           *            *             *       *      \t\t\t\t\t\n"
         << "\t\t\t\t* * * *     * * * * *   *           * * * * *   *               *      *      \t\t\t\t\t\n";
    textcolor(WHITE);
    cout << "Press to back to Menu....";
    getch();
}

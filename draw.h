#include <iostream>
#include "game.h"
#include "console.h"
#include <cstdlib>
#include <ctime>
#include "colordisplay.h"

#define EASY '1'
#define MEDIUM '2'
#define HARD '3'
#define NEWGAME '1'
#define INTRODUCE '2'

void StartGame(char &MenuChoose);
void NewGame(char &n);
void Introduce();
void Victory();
void Defeat();

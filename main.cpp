#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Launch.h"
#include "tile.h"

void clearScreen();
void gameExit();
char* gameNew();
int ansCheck(int ans);

Launch game;

int main()
{
    int ans;

    std::cin >> ans;
    ansCheck(ans);
    game.startLevel(1);

    return 0;
}

void clearScreen()
{
    printf("%s", std::string(100, '\n').c_str());
}

void gameExit()
{
    exit(0);
}

//char* gameNew()
//{
//    clearScreen();
//    printf("Please enter a name for your character: ");
//    std::cin >> name;
//    clearScreen();
//    return name;
//}

int ansCheck(int ans)
{
    switch(ans){
        case 1:
            clearScreen();
            game.readInput();
            clearScreen();
            break;
        case 2:
            clearScreen();
            break;
        case 3:
            clearScreen();
            break;
        case 4:
            gameExit();
            break;
        default:
            printf("ERROR: INVALID MENU SELECTION");
            gameExit;
    }
}

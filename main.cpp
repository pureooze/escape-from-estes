#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Launch.h"
#include "tile.h"
#include "dun/dun1.h"

void clearScreen();
void gameExit();
char* gameNew();
//int ansCheck(int ans);

//begin the game, it is a globabl object because it is essentially the program
//Launch game;

int main()
{
    int ans;

    //check the users input and display the appropriate text
    std::cin >> ans;
    clearScreen();
    dun1 lev;
    //ansCheck(ans);
    //game.startLevel(1);

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

//int ansCheck(int ans)
//{
//    switch(ans){
//        case 1:
//            clearScreen();
//            game.readInput();
//            clearScreen();
//            break;
//        case 2:
//            clearScreen();
//            break;
//        case 3:
//            clearScreen();
//            break;
//        case 4:
//            gameExit();
//            break;
//        default:
//            printf("ERROR: INVALID MENU SELECTION");
//            gameExit;
//    }
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Launch.h"

using namespace std;

void clearScreen();
void gameExit();
char* gameNew(char* name);
int ansCheck(int ans, char* name);

Launch gameStart;

int main()
{
    int ans;
    char* name;

    cin >> ans;
    ansCheck(ans, name);

    return 0;
}

void clearScreen()
{
    printf("%s", string(100, '\n').c_str());
}

void gameExit()
{
    exit(0);
}

char* gameNew(char* name)
{
    clearScreen();
    printf("Please enter a name for your character: ");
    cin >> name;
    clearScreen();
    return name;
}

int ansCheck(int ans, char* name)
{
    switch(ans){
        case 1:
            name = gameNew(name);
            gameStart.startLevel(1);
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

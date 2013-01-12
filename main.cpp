#include <iostream>
#include <stdio.h>

using namespace std;

char gameStart();

int main()
{
    gameStart();
    return 0;
}

char gameStart()
{

    char ans;

    printf("Welcome to Escape from Estes!\n");
    printf("[1] New Game\n[2] Load Game\n[3] Options\n[4] Exit\n\n");

    cin >> ans;
    return ans;
}

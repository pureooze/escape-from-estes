#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Launch.h"

using namespace std;

Launch::Launch()
{
    char ans;
    string line;
    ifstream introXML("./xml/intro.xml");

    if (introXML.is_open())
    {
        while (introXML.good())
        {
            getline(introXML, line);
            cout << line << endl;
        }
    }else
        cout << "Cannot open file";

    cin >> ans;
}

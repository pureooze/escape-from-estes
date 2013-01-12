#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include <stdlib.h>

#include "tinyxml2.h"
#include "Launch.h"

using namespace std;
using namespace tinyxml2;

Launch::Launch()
{
    XMLDocument doc("");
    doc.LoadFile( "xml/intro.xml" );
    XMLText* textNode = doc.FirstChildElement( "INTRO" )->FirstChildElement( "MENU" )->FirstChild()->ToText();
    string menu(textNode->Value());
    boost::trim(menu); // removes all leading and trailing white spaces
    printf("%s\n\n", menu.c_str());
}

int Launch::startLevel(int level)
{
    char l2 = char(level);
    printf("%d", l2);
}

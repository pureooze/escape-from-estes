#include <iostream>
#include <string>
#include "boost/algorithm/string.hpp""
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "tinyxml2.h"
#include "Launch.h"

using namespace tinyxml2;

Launch::Launch()
{
    parseXML("INTRO", "MENU", "xml/intro.xml");
}

char* Launch::parseXML(char* tagA, char* tagB, char* location)
{
    XMLDocument doc("");
    doc.LoadFile(location);
    XMLText* textNode = doc.FirstChildElement(tagA)->FirstChildElement(tagB)->FirstChild()->ToText();
    std::string menu(textNode->Value());
    boost::trim(menu); // removes all leading and trailing white spaces
    std::cout << menu;
    std::cout << std::string(19, '\n');
}
void Launch::readInput()
{
    std::cout << "Enter a name [LETTERS ONLY]: ";
    std::cin >> this->name;
}

short Launch::startLevel(short level)
{
    std::string location = "xml/dun/dun";
    std::stringstream sstm;
    char loc[100];

    sstm << location << level << ".xml";
    location = sstm.str();
    strcpy (loc,location.c_str());
    parseXML("DUNGEON", "START", loc);
}

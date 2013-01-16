#include "dun1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

dun1::dun1()
{
    char a = '\0';
//    std::cout << "You are a messenger traveling from your home city, to Estes. " <<
//                  "Your lord was very clear, the message should be delivered as soon as possible. " <<
//                  "Once you arrive in Estes, you are rushed to see the king. It appears that they were expecting you. " <<
//                  "After a brief conversation, you and your squire are given a warm bed to sleep in,"<<
//                  "and you waste no time falling asleep." <<
//                  "\n[Press any key and ENTER to continue]";
//    textPlace(18);
//    std::cin >> a;
//    std::cout << "----- 4 Hours Later ----\n" <<
//                  "You awaken, there appears to be some sort of commotion in the hallway outside your room." <<
//                  "It could be something important, or maybe you should go back to sleep. What do you do?" <<
//                  "\n\n[1] Investigate\n[2] Go back to sleep";
//    textPlace(17);
//
//    a = '\0';
//    std::cin >> a;
//    while(a != '1' and a != '2'){
//        std::cin >> a;
//    }
//
//    switch(a){
//        case '1':
//            std::cout
//            break;
//        case '2':
//            std::cout << "You go back to sleep. Suddenly, you feel a blade touch you on the throat, but before you" <<
//                          " can react, it's too late. You have died.\n\nGAME OVER";
//            textPlace(17);
//            exit(0);
//            break;
//        default:
//            std::cout << "ERROR: SWITCHCASE ON DEFAULT CASE [LINE 39]\n" << a;
//            exit(0);
//    }

}

void dun1::textPlace(int mag)
{
    std::cout << std::string(mag, '\n').c_str();
}

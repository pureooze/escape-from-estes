#ifndef LAUNCH_H
#define LAUNCH_H
#include <string>

class Launch
{
    public:
        //functions
        Launch();
        void readInput();
        char* parseXML(char* tagA, char* tagB, char* location);
        short startLevel(short level);

        //variables
        char name;

    protected:
    private:


};

#endif // LAUNCH_H

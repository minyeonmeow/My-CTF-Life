#include <iostream>
#include <string>
#include <algorithm>
#include <stddef.h>

using std::string;
using std::cout;
using std::endl;
using std::reverse;

class planet{
    bool solid;
    string color;
    bool water;
    public:
    virtual void showName(){
    }
    virtual void clean(){
    }
};

class earth : public planet{
    int countries;
    public:
    virtual void showName(){
        puts("Earth");
    }
    virtual void clean(){
        puts("All people are dead now");
    }
};

class mars: public planet{
    bool bruno;
    char marsArray[100];
    public:
    virtual void showName(){
        puts("Mars");
    }
};

class Sun{
    bool light;
    public:
    void showName(){
        puts("Sun");
        printf("and light is %s!",light?"on":"off");
    }
    void showName2(){
        puts("Earth");
    }
    void showName3(){
        puts("Earth");
    }
};
int main(){
    earth *planetA = new earth();
    mars *planetB = new mars();
    Sun *planet3 = new Sun();
    planetA->showName();
    planetB->showName();
    planet3->showName();
    return 0;
}

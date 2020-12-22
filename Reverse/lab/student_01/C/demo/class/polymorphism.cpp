#include <iostream>
#include <string>
#include <algorithm>
#include <stddef.h>

using std::string;
using std::cout;
using std::endl;
using std::reverse;

class shape{
    public:
    virtual void showName(){
    }
};

class square : public shape{
    public:
    virtual void showName(){
        puts("Square |_|_|_|");
    }
};
class triangle: public shape{
    public:
    virtual void showName(){
        puts("Triangle /\\/\\/\\");
    }
};
class circle: public shape{
    public:
    virtual void showName(){
        puts("Circle oooooo");
    }
};

void Name(shape* arg){
    arg->showName();
}

int main(){
    square S;
    triangle T;
    circle C;
    Name(&S);    
    Name(&T);    
    Name(&C);    
    return 0;
}

#include <iostream>
#include <string>

using std::string;
using std::cout;

class human{
    protected:
    string nation;
    public:
    virtual string getNation(){
        return this->nation; 
    }
};

class Taiwanese : public human{
    public:
    Taiwanese(){
        nation="A virtual island, just like the virtual funciton";
    }
};

int main(){
    Taiwanese* MeiJia = new Taiwanese();
    cout << MeiJia->getNation(); 
    return 0;
}

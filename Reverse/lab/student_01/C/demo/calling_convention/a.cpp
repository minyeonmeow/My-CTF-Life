#include <iostream>

using std::string;
using std::cout;

class human{
    string nation;
    public:
    virtual string getNation(){
        return this->nation; 
    }
};


int main(){
    human* MeiJia = new human();
    cout << MeiJia->getNation(); 
    return 0;
}

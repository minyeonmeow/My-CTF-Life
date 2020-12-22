#include <iostream>
#include <string>
#include <algorithm>
#include <stddef.h>

using std::string;
using std::cout;
using std::endl;
using std::reverse;

class human{
    protected:
    string nation;
    public:
    human(){
        nation = "earth";
        this->reverseNation();
        cout << nation;
    }
    virtual string getNation(){
        return this->nation; 
    }
    virtual void reverseNation(){
        reverse(nation.begin(),nation.end()); 
    }
};

class Taiwanese : public human{
    public:
    int salary;
    Taiwanese(){
        nation="A virtual island, just like the virtual funciton";
        this->reverseNation();
    }
    virtual void reverseNation(){
        reverse(nation.begin(),nation.end()); 
    }
};

int main(){
    Taiwanese* MeiJia = new Taiwanese();
    cout << MeiJia->getNation() << endl; 
    cout << *(string *)(((char*)MeiJia)+8) << endl; //cout << MeiJia->nation; this won't work
    MeiJia->reverseNation();
    cout << MeiJia->getNation() << endl; 
    //
    cout << &(((class Taiwanese*)NULL)->salary) << endl;
    //
    return 0;
}

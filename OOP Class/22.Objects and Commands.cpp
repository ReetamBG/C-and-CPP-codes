#include <iostream>
using namespace std;

class commandObject{
    string str;
    public:
    commandObject(string s){
        str = s;
    }
    void executeCommand(){
        cout << "The string is : " << str << endl;
    }
};

class lightSwitch{
    bool isOn = false;
    public:
    void lightIsOn(){
        isOn = true;
        cout << "The light is On" << endl;
    }
    void lightIsOff(){
        isOn = false;
        cout << "The light is Off" << endl;
    }
};


int main(){
    commandObject obj1("Hello");
    obj1.executeCommand();

    lightSwitch livingRoom, kitchen;
    livingRoom.lightIsOn();
    kitchen.lightIsOn();
    livingRoom.lightIsOff();
}

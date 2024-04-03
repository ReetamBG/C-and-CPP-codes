#include <iostream>
using namespace std;

class lightSwitch{
    bool status;
    public:
    lightSwitch(bool s = false){
        status = s;
    }
    void turnOn(){
        status = true;
        cout << "Lights On" << endl;
    }
    void turnOff(){
        status = false;
        cout << "Lights Off" << endl;
    }
};

int main(){

    lightSwitch livingRoom, commonRoom;
    livingRoom.turnOn();
    commonRoom.turnOn();
    livingRoom.turnOff();

    return 0;
}
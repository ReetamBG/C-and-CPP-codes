#include <iostream>
using namespace std;

class vehicle{
    string vehi;
    public:
    vehicle(string veh = "Vehicle"){
        vehi = veh;
    }
    void make_product(){
        cout << "This is a " << vehi << endl;
    }
};

class car : public vehicle{
    public:
    car (string veh = "Car") : vehicle(veh){}
};

class bike : public vehicle{
    public:
    bike(string veh = "Bike") : vehicle(veh){}
};

int main(){

    vehicle a;
    car b;
    bike c;

    a.make_product();
    b.make_product();
    c.make_product();

    return 0;
}
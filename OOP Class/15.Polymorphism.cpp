#include<iostream>
using namespace std;

class area{
    protected:
    int length, height;
    public:
    area(int l = 0, int h = 0){
        length = l;
        height = h;
    }
    virtual int getArea() = 0;
};

class rectangle : public area{
    public:
    rectangle(int l = 0, int h = 0) : area(l, h){
    }
    int getArea(){
        return length * height;
    }
};

class triangle : public area{
    public:
    triangle(int l = 0, int h = 0) : area(l, h){
    }
    int getArea(){
            return 0.5 * length * height;
        }
};

int main(){

    rectangle rec(2, 3);
    triangle tri(2, 3);
    cout << rec.getArea() << endl;
    cout << tri.getArea() << endl;
    return 0;
}
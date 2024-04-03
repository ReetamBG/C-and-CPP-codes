#include<iostream>
using namespace std;

class shape{
    int sides;
    public:     
    shape(int s){
        sides = s;
    }
    int returnSides(){
        return sides;
    }
};

class triangle : protected shape{
    public:
    triangle(int s = 3) : shape(s){};
    void display(){
        cout << "Sides : " << returnSides() << endl;
    }
};

class rectangle : protected shape{
    public:
    rectangle(int s = 4) : shape(s){}; 
    void display(){
        cout << "Sides : " << returnSides() << endl;
    }
};

int main(){

    triangle t;
    rectangle r;
    t.display();
    r.display();

    return 0;
}
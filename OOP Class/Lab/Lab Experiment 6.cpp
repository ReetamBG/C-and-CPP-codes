#include <iostream>
using namespace std;

class shape{
    protected:
    float breadth, height;
    public:
    shape(float b = 0, float h = 0){
        breadth = b;
        height = h;
    }
    void get_data();
    virtual void display_area() = 0;
};

class triangle : public shape{
    public:
    triangle(float b = 0, float  h = 0) : shape(b, h){}
    inline void display_area();
};

class rectangle : public shape{
    public:
    rectangle(float b = 0, float h = 0) : shape(b, h){}
    inline void display_area();
};

int main(){

    int choice;
    triangle tri;
    rectangle rec;
    do{
        cout << "Select option : " << endl
        << "1. Traingle" << endl
        << "2. Rectangle" << endl
        << "3. Exit " << endl;
        cin >> choice;
        switch(choice){
            case 1:
            tri.get_data();
            tri.display_area();
            break;
            case 2:
            rec.get_data();
            rec.display_area();
            break;
            case 3:
            break;
            default: 
            cout << "Invalid Option" << endl;
            break;
        }
    }
    while(choice != 3);

    return 0;
}

// Function Definitions

void shape :: get_data(){
    cout << "Enter Width : ";
    cin >> breadth;
    cout << "Enter Height : ";
    cin >> height;
}

inline void triangle :: display_area(){
    cout << "Area of Triangle = " << 0.5 * breadth * height << endl;
}

inline void rectangle :: display_area(){
    cout << "Area of Rectangle = " << breadth * height << endl;
}
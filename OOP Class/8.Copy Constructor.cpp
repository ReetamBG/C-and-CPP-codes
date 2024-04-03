#include<iostream>
using namespace std;

class vector{
    public:
    int x, y;
    vector(){
        x = 0;
        y = 0;
    }
    vector(int a, int b){
        x = a;
        y = b;
    }
    vector(vector &p){                                          // Must use call by reference for copy constructor
        cout << "Copy constructor initialised" << endl;         // Copy Constructor
        x = p.x;
        y = p.y;
    }
    void display(){
        cout << x << endl << y << endl;
    }
};

int main(){

        vector a, b(10, 10), c(b);      // The copy constructor simply copies property of one class into another. Mostly needed if using pointers.
        a.x = 5;                        // Here as per the definition c will take parameter b and as the copy constructor is defined will copy b.x and b.y into c.
        a.y = 15;
        a.display();
        b.display();
        c.display();

        vector d = a;        // This will also initialise copy constructor but decalring d before and assigning it later wont
        d.display();

        return 0;
}
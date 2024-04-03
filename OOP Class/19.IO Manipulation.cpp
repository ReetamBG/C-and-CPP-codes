#include<iostream>
#include <iomanip>  //for setw()
using namespace std;

int main(){

    cout.width(10);
    cout << "Hello";
    cout.width(3);
    cout << "No" << endl;

    float a = 3.1416780954;
    cout.precision(4);
    cout << a << endl;

    char p[10];
    fill(p, p + 5, 'y');
    cout << p << endl;

    cout << "Hello" << setw(5) << "World" << endl;
    return 0;
}

#include<iostream>
using namespace std;

class vector{
    public:
    double abc = 10;
    double bc = 3.00;
};

int main(){

    vector *a, b;
    a = &b;
    //float c = 2.00;
    //int *p = &c;
    cout << sizeof(vector) << endl;
    cout << sizeof(a) << endl;
    cout << a->abc << endl;          // Either this 
    cout << (*a).abc << endl;        // or this

    return 0;
}
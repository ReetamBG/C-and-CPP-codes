#include<iostream>
#include <cstring>
using namespace std;

class test{
    public:
    int a, b;
    char *name;
    test(int x = 0, int y = 0, char *str = "Hell"){
        a = x;
        b = y;
        name = new char[10];
        strcpy(name, str);
        cout << "Constructor Initialised" << endl;
    }
    ~test(){
        delete [] name;
    }

    int sum(){
        return a+b;
    }

    void display(){
        cout << name << endl;
    }
};

int main(){

    test a;
    cout << a.sum() << endl;
    a.display();

    return 0;
}
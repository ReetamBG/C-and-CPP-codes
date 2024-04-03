#include<iostream>   //make a class with a function to get sum and overload + to *
using namespace std;

class sum{
    public:
        int x, y;
        int func(){
            return x + y;
        }
        int operator+ (sum a){
            return a.x * a.y;
        }
};

int main(){

    sum abc;
    abc.x = 10;
    abc.y = 5;

    cout << abc.func() << endl;

    cout << abc+abc;

    return 0;
}
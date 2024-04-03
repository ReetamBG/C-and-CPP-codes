#include<iostream>
using namespace std;

struct xyz{
    int x, y;
    int p(){
        x = x + 5;
        y = y + 10;

        return x, y;
    }
}abc;

int main(){

    abc.x = 1;
    abc.y = 2;

    abc.p();
    cout << abc.x << endl << abc.y << endl;

    return 0;
}
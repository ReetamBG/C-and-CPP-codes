#include<iostream>
using namespace std;

int main(){

    int *a = new int;
    *a = 3;
    cout << *a << endl;
    delete a;

    return 0;
}
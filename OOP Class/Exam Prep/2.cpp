#include<iostream>
using namespace std;

template <class type1, class type2>

type1 sum(type1 a, type2 b){
    return a + type1(b);
}

int main(){

    int a = 10, b = 20;
    float c = sum(2.33, 2);
    cout << c << endl;

    return 0;
}
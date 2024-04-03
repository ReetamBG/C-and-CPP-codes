#include<iostream>
using namespace std;

template <class type1, class type2>

//template function to add any kind of data
type1 sum(type1 x, type2 y){                    //can we not define template functions after the main function??
    return x + type1(y);
}

int main(){

    int a = 10;
    float b = 20.25;

    cout << sum(a, b) << endl;

    return 0;
}

// type1 sum(type1 x, type2 y){       
//     return x + type1(y);
// }
#include<iostream>
using namespace std;

template <class type>
type big(type a, type b){
    type big = a;
    if(b > a){
        big = b;
    }
    return big;
}

int main(){

    cout << big(2, 3) << endl;
    cout << big('a', 'b') << endl;
    cout << big(2.4, 2.1) << endl;

    return 0;
}
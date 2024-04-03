#include<iostream>
using namespace std;

struct test{
    int x = 2;
};

void operator + (istream& print, test a){
    print >> a.x;
}

void operator + (ostream& print, test a){
    print << a.x;
}

int main(){

    test abc;
    cin + abc;
    cout + abc;
    cout << endl;

    return 0;
}
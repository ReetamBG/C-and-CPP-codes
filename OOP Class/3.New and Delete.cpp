#include<iostream>
using namespace std;

int main(){

    int *p;
    p = new int[30];
    int *q;
    q = p;

    for (int i = 0; i < 10; i++)
    {
        cin >> *(p+i) ;    
    }   
    
    while(*p){
        cout << *p << "  ";
        p++;
    }

    cout << endl;
    delete q;

    return 0;
}
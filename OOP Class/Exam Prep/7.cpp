#include<iostream>
using namespace std;

int main(){

    char c;
    
    do{
        cin.get(c);
        cout.put(c);
    }
    while(c != '\n');

    char *ch;
    ch = new char[10];
    cin.getline(ch, 10);
    cout.write(ch, 9);

    return 0;
}
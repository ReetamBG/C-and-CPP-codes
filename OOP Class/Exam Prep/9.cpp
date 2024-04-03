#include <iostream>
#include <fstream>
using namespace std;

int main(){

    fstream test;
        char *c, *c2;
        c = new char[10];
        c2 = new char[10];
    test.open("File.txt", ios::app);
    if(test.is_open() == 0){
        cout <<"Error" << endl;
    }
    else{
        cin.getline(c, 10);
        test << c;
        test.close();
    }
    
    test.open("File.txt");
    if(test.is_open() == 0){
        cout <<"Error" << endl;
    }
    else{
        test >> c2;
        cout.write(c2, 9);
        test.close();
    }

    return 0;
}
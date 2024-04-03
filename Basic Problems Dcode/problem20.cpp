#include<iostream>
using namespace std;

int main(){
    
    string str;
    cout << "Enter the string : " << endl;
    getline(cin,str);
    cout << "The length of the string is : " << str.length() << endl;

    return 0;
}
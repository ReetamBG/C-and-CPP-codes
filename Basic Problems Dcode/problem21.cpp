#include<iostream>
using namespace std;

int main(){

    string s1, s2;
    cout << "Enter the first string : " << endl;
    getline(cin, s1);
    cout << "Enter the second string : " << endl;
    getline(cin, s2);
    cout << "The concatenated string is : " << s1 << " " << s2 << endl;

    return 0;
}
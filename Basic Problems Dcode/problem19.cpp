#include<iostream>
using namespace std;

string reverse(string str, int length){

    char temp;

    for (int i = 0; i < length; i++){
        temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }

    return str;
}

int main(){

    string str;
    getline(cin, str);

    int length = str.length();

    cout << reverse(str, length) << endl;  

    return 0;
}
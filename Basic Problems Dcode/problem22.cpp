#include<iostream>
using namespace std;

int main(){

    string str;

    cout << "Enter the string : ";
    getline (cin, str);

    for (int i = 0; i < str.length(); i++){
        if (str[i] == 'a' ||  str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            str.erase (i, 1);
        }
    }

    cout << "The new string is : " << str << endl;

    return 0;
}
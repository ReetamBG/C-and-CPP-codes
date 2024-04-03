#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;
    try{
        if(a > b){
            throw "a is bigger";
        }
        throw "b is bigger";
    }
    catch(const char *result){
        cout << result << endl;
    }
    
    return 0;
}
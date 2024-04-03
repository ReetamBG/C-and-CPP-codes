#include<iostream>
#include<cmath>
using namespace std;

void isAutomorphic(){
    int n,count = 0;
    cout << "Enter the number : ";
    cin >> n;
    int N = n*n;
    while ( n != 0 ){
        if ( n % 10 != N % 10){
            count++;
            break;
        }
        n/=10;
        N/=10;
    }
    if (count == 0){
        cout<<"The number is automorphic"<<endl;
    }
    else{
        cout<<"The number is not automorphic"<<endl;
    }
}

int main(){
    isAutomorphic();
    return 0;
}
    
        
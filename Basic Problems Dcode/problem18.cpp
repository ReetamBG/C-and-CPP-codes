#include<iostream>
using namespace std;

int search(int arr[], int number, int size){

    for (int i = 0; i < size; i++){
        if (arr[i] == number){
            return 1;
        }
    }
}
    

int main(){

    int n, number;

    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the Elements of the array : " << endl;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Enter the character : ";
    cin >> number;

    if(search(arr ,number, n) == 1){
        cout << "The element is present in the array." <<  endl;
    }
    else{
        cout << "The element is not present in the array." << endl;
    }

    return 0;
}
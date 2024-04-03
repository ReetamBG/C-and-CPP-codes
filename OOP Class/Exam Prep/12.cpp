#include <iostream>
using namespace std;

class ARRAY{
    int *arr, size;
    public:
    ARRAY(int s){
        arr = new int[size];
    }
    void setData(int data, int index){
        if(index > size - 1){
            cout << "Out of Bounds" << endl;
        }
        else{
            arr[index] = data;
        }
    }
    void resize(int newSize){
        size = newSize;
        int copySize = (newSize < size) ? newSize : size;
        int *newArr = new int[size];
        for(int i = 0; i < copySize; i++){
            newArr[i] = arr[i];
        }
        delete []arr;
        arr = newArr;
    }
};

int main(){

    ARRAY arr(3);


    return 0;
}
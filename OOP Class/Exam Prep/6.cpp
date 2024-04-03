#include<iostream>
using namespace std;

class test{
    private:
    int a;
    public:
    int b;
    test(int x){
        b = x;
    }
    int sum(){
        return b + 10;
    }
};

class test1 : public test{
    public:
    int c;
    test1(int x = 0, int y = 0) : test(x){
        c = y;
    }
    int sum(){
        return b + c + 10;
    }
};

int main(){

    return 0;
}
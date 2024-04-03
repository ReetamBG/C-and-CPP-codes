#include<iostream>
using namespace std;

template <class type>
class abc{
    type member1;
    type member2;
    public:
    abc(type a, type b){
        member1 = a;
        member2 = b;
    }
    type func(){
        return member1 + member2;
    }
};

int main(){

    abc <int> a(2, 3);
    abc <float> (1.2, 3.5);

    return 0;
}
#include<iostream>
using namespace std;

class person{
    private:
    string name;
    int age;
    public:
    person(string n = "No Name", int a = 0){
        name = n;
        age = a;
    }
    void display(){
        cout << "Name : " << name << endl << "Age : " << age << endl;
    }
};

int main(){

    person abc("Ree", 19);
    abc.display();

    return 0;
}
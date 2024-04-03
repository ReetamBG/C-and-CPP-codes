#include<iostream>
#include<cstring>
using namespace std;

class vector{
    public:
    char *name;
    vector(char str[30]){
        cout << "Constructor Initialised" << endl;
        name = new char[30];
        strcpy(name, str);
    }
    vector(vector &obj){            // Example of proper use of copy constructor i.e for pointers 
        name = new char[20];
        // name = obj.name;      Dont use this or it will be worthless to use copy constructor as it will be same as assigning in main function. Result in memory zombie and all idk what that is
        strcpy(name, obj.name);     
        cout << name << endl;
    }
    ~vector(){
        cout << "Destructor Initialised" << endl;
        delete name;
    }
};

int main(){

    vector abc("Ree");
    cout << abc.name << endl;
    vector pqr(abc);

    return 0;
}
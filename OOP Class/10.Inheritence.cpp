#include<iostream>
using namespace std;

class student{
    public:
    string name;
    int id;

    student(string std_name, int std_id){
        name = std_name;
        id = std_id;
    }

    void display(){
        cout << "Name : " << name << endl << "ID : " << id << endl << endl;
    }
};

class undergraduate : public student{
    public:
    int year;
    
    undergraduate(string std_name, int std_id, int std_year) : student(std_name, std_id){
        year = std_year;
    }

    void display2(){
        cout << "Undergraduate " << endl << "Name : " << name << endl << "ID : " << id << endl << "Year : " << year << endl << endl;
    }
};

int main(){

    student abc("Ree", 2048);
    undergraduate xyz("Karan", 1056, 2);

    abc.display();
    xyz.display2();

    return 0;
}

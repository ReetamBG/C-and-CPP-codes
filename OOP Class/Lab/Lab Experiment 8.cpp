#include <iostream>
using namespace std;

class model{
    private:
    string a;
    public:
    model(string str){
        a = str;
    }
        string data(){
        return a;
    }
    string data_base(){
        if(a == "Hello"){
            return ("FOUND");
        }
        else{
            return ("NOT FOUND");
        }
    }    
};

class controller{
    private:
    model abc;
    string x; 
    public:
    controller(const string ptr) : abc(ptr){}
    string data(){
        return abc.data();;
    }
    void display(){
        x = abc.data_base();
        cout << x << endl;
    }
    
};

class view{
    private:
    controller pqr;
    public:
    view(const string ptr) : pqr(ptr){}
    void display_data(){
        cout << pqr.data() << endl;
    }
};

int main(){

    controller obj1("Hello");
    obj1.display();

    return 0;
}
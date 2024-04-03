#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    cout.width(5);
    cout.fill('*');
    cout << setw(10);
    cout << setfill('*');

    return 0;
}
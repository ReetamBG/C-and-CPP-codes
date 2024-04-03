#include<iostream>
using namespace std;

struct vector{
	int x, y;
};

ostream& operator >> (ostream& o, vector a){
	o << a.x;
	return o;
}

int main(){

	vector a;
	a.x = 15;
	cout >> a;

	return 0;
}

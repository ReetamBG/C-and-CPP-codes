#include<iostream>
using namespace std;

struct vector{
	int x, y;
};

vector operator + (int a, vector b){
	vector m;
	m.x = a - b.x;
	m.y = a - b.y;

	return m;
}

int main(){

	vector p, q;
	p.x = 2;
	q.y = 3;
	q = 10 + p;    //does using it like this means that it will operate on p.x and q.x or p.y and q.y ??

	cout << q.x << endl;

	return 0;
}

	


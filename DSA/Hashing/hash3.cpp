#include <iostream>
#include <vector>
using namespace std;

int main(){
	cout << "Enter the letters (Enter 0 to exit)" << endl;
	vector<char> arr;
	char x;
	do{
		cin >> x;
		arr.push_back(x);
	}
	while(x != '0');

	// Creating the hashmap
	int hash[256] = {0};		           // To hash all the characters take size 256

	// Finding the number of occurances
	for(int i=0; i<arr.size(); i++){
		hash[arr[i]]++;                    // Stroing chars in int array will automatically make it ASCII value
	}
	do{
		cout << "Enter the letter (0 to exit) : " << endl;
		cin >> x;
		cout << "The number of occurances of " << x << " is " << hash[x] << endl;
	}
	while(x != '0');
}

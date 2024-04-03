// Hashing Letters
// We use the concept of ASCII
// We can use the ASCII values by simply storing the character in int or by doing arithmetic operations

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
	int hash[26] = {0};		            // Size = 26 cuz 26 letters (Assuming small letters only)

	// Finding the number of occurances
	for(int i=0; i<arr.size(); i++){
		hash[arr[i]-'a']++;             // ASCII val of a-a = 0, b-a = 1, ... z-a = 25. So we can store it in the hashmap
	}
	do{
		cout << "Enter the letter (0 to exit) : " << endl;
		cin >> x;
		cout << "The number of occurances of " << x << " is " << hash[x-'a'] << endl;
	}
	while(x != '0');
}

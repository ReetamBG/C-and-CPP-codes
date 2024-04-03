// Hashing Numbers

#include <iostream>
#include <vector>
using namespace std;

int main(){
	cout << "Enter the array (Enter -1 to exit)" << endl;
	vector<int> arr;
	int x;
	do{
		cin >> x;
		arr.push_back(x);
	}
	while(x != -1);

	// Creating the hashmap
	cout << "Enter the largest number in the array : " << endl;
	cin >> x; 
	int hash[x+1] = {0};		// Initialise all members as 0
	

	// Finding the number of occurances
	for(int i=0; i<arr.size(); i++){
		hash[arr[i]]++;
	}
	do{
		cout << "Enter the number (-1 to exit) : " << endl;
		cin >> x;
		cout << "The number of occurances of " << x << " is " << hash[x] << endl;
	}
	while(x != -1);
}


// Resource : https://www.youtube.com/watch?v=KEs5UyBJ39g
// Hashmap

#include <iostream>
#include <vector>
#include <map>                  // For ordered map
#include <unordered_map>        // For unordered map
using namespace std;

int main(){
	cout << "Enter the array (Enter 0 to exit)" << endl;
	vector<int> arr;
	int x;
	do{
		cin >> x;
		arr.push_back(x);
	}
	while(x != 0);

    // Creating the map
    unordered_map<int, int> hmap;            
    // First parameter is the key, second is the value (number of occurances of the key in this case
    // Use unordered_map for most cases as it gives O(1) for best and average cases compared to O(n) if we use only 'map'

	// To iterate through the map
	for(auto it : hmap){
		cout << it.first << " -> " << it.second << endl;
	}

	// Finding the number of occurances
	for(int i=0; i<arr.size(); i++){
		hmap[arr[i]]++;
	}

	do{
		cout << "Enter the number (0 to exit) : " << endl;
		cin >> x;
		cout << "The number of occurances of " << x << " is " << hmap[x] << endl;
	}
	while(x != 0);
}


// Resource : https://www.youtube.com/watch?v=KEs5UyBJ39g
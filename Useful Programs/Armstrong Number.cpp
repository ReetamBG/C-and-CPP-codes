#include <iostream>
#include <cmath>
using namespace std;

void isArmstrong(){
	int num;
	cin >> num;
	int temp = num, digits =5 0, sum = 0, rem;
    // To check the number of digits
	while(temp != 0){                   
		temp / 10;
		digits++;
	}
	cout << "Digits : " << digits << endl;
	temp = num;
    // To check if it is an Armstrong number
	while(temp != 0){
		rem = (temp % 10);
		sum += pow(rem, digits);
		temp / 10;
	}
	if(sum == num){
		cout << "It is an Armstrong number" << endl;
	}
	else{
		cout << "It is not" << endl;
	}
}

int main(){
	isArmstrong();
	return 0;
}

// #include <iostream>
// #include<cmath>
// using namespace std;

// int isArmstrong(int num);

// int main() {
//     int num;

//     // Input a number from the user
//     cout << "Enter a number: ";
//     cin >> num;

//     // Check if the number is an Armstrong number
//     if (isArmstrong(num)) {
//         cout << num << " is an Armstrong number." << endl;
//     } else {
//         cout << num << " is not an Armstrong number." << endl;
//     }

//     return 0;
// }

// int isArmstrong(int num) {
//     int originalNum, remainder, result = 0, n = 0;

//     originalNum = num;

//     // Calculate the number of digits
//     while (originalNum != 0) {
//         originalNum /= 10;
//         ++n;
//     }

//     originalNum = num;

//     // Calculate sum of nth power of individual digits
//     while (originalNum != 0) {
//         remainder = originalNum % 10;
//         result += pow(remainder, n);
//         originalNum /= 10;
//     }

//     // Check if the sum is equal to the original number
//     return result == num;
// }

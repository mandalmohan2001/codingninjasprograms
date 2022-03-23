#include <iostream>
#include <climits>
using namespace std;

void printArray(int input[], int n) {
	// cout << "Function : " << sizeof(input) << endl;
	
	cout << "Print : " << endl;
	for(int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
}

int main() {
	// Take array input from the user

	int n;
	cout << "Enter n : ";
	cin >> n;

	int input[100];

	cout << "Enter array elements : ";
	cout << input << endl;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	// cout << "Main : " << sizeof(input) << endl;
	printArray(input, n);

	/*
	// Print array
	for (int i = 0; i < n; i++) {
		cout << input[i] << endl;
	}

	// Largest element in the array 

	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if(input[i] > max) {
			max = input[i];
		}
	}

	cout << "Max : " << max << endl;
	*/
}

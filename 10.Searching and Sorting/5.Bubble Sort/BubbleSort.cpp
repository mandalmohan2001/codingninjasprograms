#include <iostream>
using namespace std;

void printArray(int input[], int n) {
	for(int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int arr[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - 1 - i; j++) {
			if(arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] =  temp;
			}
		}
	}
}

int main() {
	// Take array input from the user 
	int n;
	cin >> n;

	int input[100];

	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}

	bubbleSort(input, n);

	printArray(input, n);
}

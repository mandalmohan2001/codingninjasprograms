#include <iostream>
using namespace std;

void selectionSort(int input[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for(int j = i; j < n; j++) {
			if(input[j] < input[minIndex]) {
				minIndex = j;
			}
		}
		int temp = input[i];
		input[i] = input[minIndex];
		input[minIndex] = temp;
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

	selectionSort(input, n);

	for(int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}
	cout << endl;

	return 0;
}

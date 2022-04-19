Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
  
// Code
#include <iostream>
using namespace std;

int partition(int input[], int startIndex, int endIndex) {
	int count = 0;
	for(int i = startIndex + 1; i <= endIndex; i++) {
		if(input[i] <= input[startIndex]) {
			count++;
		}
	}

	int pivotIndex = startIndex + count;

	int temp = input[startIndex];
	input[startIndex] = input[pivotIndex];
	input[pivotIndex] = temp;

	int i = startIndex;
	int j = endIndex;
	while(i < pivotIndex && j > pivotIndex) {
		if(input[i] <= input[pivotIndex]) {
			i++;
		} else if(input[j] > input[pivotIndex]) {
			j--;
		} else {
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}

	return pivotIndex;
}

void quickSort(int input[], int startIndex, int endIndex) {
	//Base case 
	if(startIndex >= endIndex) {
		return;
	}

	int pivot = partition(input, startIndex, endIndex);
	quickSort(input, startIndex, pivot - 1);
	quickSort(input, pivot + 1, endIndex);
}

void quickSort(int input[], int size) {
	quickSort(input, 0, size - 1);
}

int main() {
	int n;
	cin >> n;

	int *input = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> input[i];
	}	

	quickSort(input, n);
	for(int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}

	delete [] input;
	return 0;
}

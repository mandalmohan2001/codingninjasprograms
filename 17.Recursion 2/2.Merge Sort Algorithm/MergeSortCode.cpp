Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 

// Code
#include <iostream>
using namespace std;

void merge(int input[], int startIndex, int mid, int endIndex) {
	int *temp = new int[endIndex + 1];
	int i = startIndex;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= endIndex) {
		if(input[i] <  input[j]) {
			temp[k] = input[i];
			i++;
			k++;
		} else {
			temp[k] = input[j];
			j++;
			k++;
		}
	}
	while(i <= mid) {
		temp[k] = input[i];
		i++;
		k++;
	}
	while(j <= endIndex) {
		temp[k] = input[j];
		j++;
		k++;
	}
	i = startIndex;
	j = 0;
	for(; j < k; j++, i++) {
		input[i] = temp[j];
	}
}

void mergeSort(int input[], int startIndex, int endIndex) {
	// Base case
	if(startIndex >= endIndex) {
		return;
	}
	int mid = (startIndex + (endIndex - startIndex) / 2);
	mergeSort(input, startIndex, mid);
	mergeSort(input, mid + 1, endIndex);
	merge(input, startIndex, mid, endIndex);
}

void mergeSort(int input[], int size) {
	mergeSort(input, 0, size - 1);
}

int main() {
	int length;
	cin >> length;
	int *input = new int[length];
	for(int i = 0; i < length; i++) {
		cin >> input[i];
	}	
	mergeSort(input, length);
	for(int i = 0; i < length; i++) {
		cout << input[i] << " ";
	}
	delete [] input;
	return 0;
}

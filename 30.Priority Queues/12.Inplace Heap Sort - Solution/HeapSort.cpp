#include <iostream>
using namespace std;

void inplaceHeapSort(int input[], int n) {
	// Build the heap in input array
	for(int i = 1; i < n; i++) {
		int childIndex = i;

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(input[childIndex] < input[parentIndex]) {
				int temp = input[parentIndex];
				input[parentIndex] = input[childIndex];
				input[childIndex] = temp;
			} else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	// Remove elements  
	int size = n - 1;
	while(size >= 0) {
		int temp = input[0];
		input[0] = input[size];
		input[size] = temp;
		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;

		while(leftChildIndex <= size) {
			int minIndex = parentIndex;
			if(input[minIndex] > input[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndex <= size && input[minIndex] > input[rightChildIndex]) {
				minIndex = rightChildIndex;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = input[minIndex];
			input[minIndex] =  input[parentIndex];
			input[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
		}
	}
}

int main() {
	int input[] = {1, 2, 3, 4, 5};
	inplaceHeapSort(input, 5);
	for(int i = 0; i < 5; i++) {
		cout << input[i] << " ";
	}
	cout << endl;
	return 0;
}

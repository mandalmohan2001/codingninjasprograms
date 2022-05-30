#include <iostream>
using namespace std;

void heapSort(int arr[], int n) {
    // Write your code
    // Up-heapify
    for(int i = 1; i < n; i++) {
        int childIndex = i;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(arr[childIndex] < arr[parentIndex]) {
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    // Down-heapify
    int i = n - 1;
    while(i >= 0) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        i--;
        
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        
        while(leftChildIndex <= i) {
            int minIndex = parentIndex;
            if(arr[minIndex] > arr[leftChildIndex]) {
                minIndex = leftChildIndex;
            } 
            if(rightChildIndex <= i && arr[minIndex] > arr[rightChildIndex]) {
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex) {
                break;
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

int main() {
	int size;
	cin >> size;

	int *input = new int[size];

	for(int i = 0; i < size; i++) {
		cin >> input[i];
	}	

	heapSort(input, size);

	for(int i = 0; i < size; i++) {
		cout << input[i] << " ";
	}

	delete[] input;
	return 0;
}

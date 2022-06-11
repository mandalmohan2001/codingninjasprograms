#include <iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight) {
	// Base case 
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weights[0] > maxWeight) {
		return knapsack(weights + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls 
	int x = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
	int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);
	return max(x, y);
}

int main() {
	int n;
	int weights[] = {5, 1, 8, 9, 2};
	int values[] = {4, 10, 2, 3, 1};
	int W = 15;
	cout << knapsack(weights, values, 5, W) << endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int minCostPath_DP(int **input, int m, int n) {
	int **output = new int*[m];
	for(int i = 0; i < m; i++) {
		output[i] = new int[n];
	}

	// Fill the last cell i.e. destination
	output[m - 1][n - 1] = input[m - 1][n - 1];

	// Fill last row (right to left)
	for(int j = n - 2; j >= 0; j--) {
		output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
	}

	// Fill last column (bottom to top)
	for(int i = m - 2; i >= 0; i--) {
		output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
	}

	// Fill remaining cells
	for(int i = m - 2; i >= 0; i--) {
		for(int j = n - 2; j >= 0; j--) {
			output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
		}
	}
	return output[0][0];
}

int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
	if(i == m - 1 && j == n - 1) {
		return input[i][j];
	}

	if(i == m || j == n) {
		return INT_MAX;
	}

	// Check if output already exists
	if(output[i][j] != -1) {
		return output[i][j];
	}

	// Recursive call
	int x = minCostPath_Mem(input, m, n, i, j + 1, output);
	int y = minCostPath_Mem(input, m, n, i + 1, j + 1, output);
	int z = minCostPath_Mem(input, m, n, i + 1, j, output);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];

	// Save the answer for future use
	output[i][j] = ans;

	return output[i][j];
}

int minCostPath(int **input, int m, int n) {
	int **output = new int*[m];
	for(int i = 0; i < m; i++) {
		output[i] = new int[n];
		for(int j = 0; j < n; j++) {
			output[i][j] = -1;
		}
	}
	return minCostPath_Mem(input, m, n, 0, 0, output);
}

int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}
	cout << minCostPath_DP(input, m, n) << endl;
	for(int i = 0; i < m; i++) {
		delete [] input[i];
	}
	delete [] input;
	return 0;
}

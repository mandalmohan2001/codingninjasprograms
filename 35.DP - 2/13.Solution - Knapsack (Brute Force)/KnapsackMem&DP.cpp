A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
  
// Code
#include <cstring>
#include <iostream>
using namespace std;

int knapsack(int* weight, int* value, int n, int maxWeight) {
    // Write your code here
    int **output = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        output[i] = new int[maxWeight + 1];
    }
    
    // Fill the last row
    for(int j = 0; j <= maxWeight; j++) {
        output[n][j] = 0;
    }
    
    // Fill the 1st
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= maxWeight; j++) {
            if(weight[i] > j) {
                output[i][j] = output[i + 1][j];
            } else {
                output[i][j] = max(value[i] + output[i + 1][j - weight[i]], output[i + 1][j]);
            }
        }
    }
    return output[0][maxWeight];
}

/*
// Memoization
int knapsack(int* weights, int* values, int n, int maxWeight, int **output) {
    if(n == 0 || maxWeight == 0) {
        return 0;
    }
    
    if(output[maxWeight][n] != -1) {
        return output[maxWeight][n];
    }

    int ans;
    if(weights[0] > maxWeight) {
        ans = knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
        output[maxWeight][n] = ans;
        return ans;
    }

    // Recursive calls 
    int x = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], output) + values[0];
    int y = knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
    ans = max(x, y);
    output[maxWeight][n] = ans;
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
    // Write your code here
    int **output = new int*[maxWeight + 1];
    for(int i = 0; i <= maxWeight; i++) {
        output[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    return knapsack(weight, value, n, maxWeight, output);
}
*/

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
    return 0;
}

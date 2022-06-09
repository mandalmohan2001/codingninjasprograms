Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
  
// Code
#include <iostream>
using namespace std;

#include <cmath>

// Dynamic programming approach
int balancedBTs(int n) {
    // Write your code here
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    int mod = (int)(pow(10, 9)) + 7;
    for(int i = 2; i <= n; i++) {
        int x = ans[i - 1];
        int y = ans[i - 2];
        
        int temp1 = (int)(((long)(x) * x) % mod);
        int temp2 = (int)((2 * (long)(x) * y) % mod);
        int output = (((long)(temp1) + temp2) % mod);
        
        ans[i] = output;
    }
    return ans[n];
}

/*
// Memoization method
int balancedBTsHelper(int n, int *ans) {
    // Base case 
	if(n <= 1) {
        return 1;
    }
    
    // Check if output already exists
    if(ans[n] != -1) {
        return ans[n];
    }
    
    // Calculate the output 
    int mod = (int)(pow(10, 9)) + 7;
	int x = balancedBTsHelper(n - 1, ans);
	int y = balancedBTsHelper(n - 2, ans);

	int temp1 = (int)(((long)(x) * x) % mod);
	int temp2 = (int)((2 * (long)(x) * y) % mod);
	int output = (((long)(temp1) + temp2) % mod);
    
    // Save the output for future use
    ans[n] = output;
    
    return ans[n];
}

int balancedBTs(int n) {
    // Write your code here
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    return balancedBTsHelper(n, ans);
}
*/

int main() {
	int n;
	cin >> n;
	cout << balancedBTs(n);	
	return 0;
}

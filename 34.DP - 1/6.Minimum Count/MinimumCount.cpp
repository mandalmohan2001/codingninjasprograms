Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
  
// Code
#include <bits/stdc++.h>
using namespace std;

// Dynamic programming approach
int minCount(int n) {
	//Write your code here
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 1; i <= n; i++) {
        int minimum = i;
        for(int j = 1; j * j <= i; j++) {
            int count = ans[i - (j * j)];
            minimum = min(count, minimum);
        }
        ans[i] = 1 + minimum;
    }
    return ans[n];
}

/*
// Memoization method
int solver(int n, int *ans) {
    // Base case 
    if(n == 0) {
        return 0;
    }
    
    // Check if output already exists
    if(ans[n] != -1) {
        return ans[n];
    }
    
    // Calculate the output 
    int minimum = INT_MAX;
    for(int i = 1; i * i <= n; i++) {
        int count = solver(n - (i * i), ans);
        minimum = min(minimum, count);
    }
    
    // Save the output for future use
    ans[n] = 1 + minimum;
    
    return ans[n];
}

int minCount(int n) {
	//Write your code here
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    return solver(n, ans);
}
*/

/*
// Brute force approach
int minCount(int n) {
	//Write your code here
    // Base case 
    if(n == 0) {
        return 0;
    }
    
    int minimum = INT_MAX;
    for(int i = 1; i * i <= n; i++) {
        int count = minCount(n - (i * i));
        minimum = min(minimum, count);
    }
    
    return 1 + minimum;
}
*/

int main() {
    int n;
    cin >> n;
    cout << minCount(n);
}

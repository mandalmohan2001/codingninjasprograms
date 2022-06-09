A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274
  
// Code
#include<bits/stdc++.h>
using namespace std;

int solver(int n) {
   	vector<long long int> ans;
    ans.push_back(0);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(4);
    
    for(int i = 4; i <= n; i++) {
        ans.push_back((ans[i - 1] + ans[i - 2] + ans[i - 3]) % 1000000007);
    }
    
    return ans[n];
}
	
int main(){
    // write your code here
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << solver(n) % 1000000007 << endl;
    }
    return 0;
}

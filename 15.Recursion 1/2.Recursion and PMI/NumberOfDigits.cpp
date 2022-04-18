Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.
Input Format :
Integer n
Output Format :
Count of digits
Constraints :
1 <= n <= 10^6
Sample Input 1 :
 156
Sample Output 1 :
3
Sample Input 2 :
 7
Sample Output 2 :
1
  
// Code
#include <iostream>
using namespace std;

int count(int n) {
	if(n == 0) {
		return 0;
	}
	int smallOutput = count(n / 10);
	int output = 1 + smallOutput;
	return output;
}

int main() {
	int n;
	cin >> n;

	cout << count(n) << endl;	
	return 0;
}
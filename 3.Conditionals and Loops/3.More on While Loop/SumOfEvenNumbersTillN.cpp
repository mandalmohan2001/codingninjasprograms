Given a number N, print sum of all even numbers from 1 to N.
Input Format :
Integer N
Output Format :
Required Sum 
Sample Input 1 :
 6
Sample Output 1 :
12

//Code
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int i = 1;
	while(i <= n) {
		if(i % 2 == 0) {
			sum = sum + i;
		}
	}
	cout << sum << endl;
}

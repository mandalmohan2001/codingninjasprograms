Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
Fibonacci Series is defined by the recurrence
    F(n) = F(n-1) + F(n-2)
where F(0) = 0 and F(1) = 1


Input Format :
Integer N
Output Format :
true or false
Constraints :
0 <= n <= 10^4
Sample Input 1 :
5
Sample Output 1 :
true
Sample Input 2 :
14
Sample Output 2 :
false    
  
//Code
#include <iostream>
using namespace std;

bool checkMember(int n) {
	int a = 0, b = 1;
	while(a <= n) {
		if(a == n) {
			return true;
		}
		int c = a + b;
		a = b;
		b = c;
	}
	return false;
}

int main() {

	int n;
	cin >> n;
	if(checkMember(n)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
}

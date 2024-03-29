Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)
Constraints :
0 <= N <= 10^9
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7

// Code
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int base = 2;
	int i = 0;
	int ans = 0;
	while(n) {
		int rem = n % 10;
		ans = ans + rem * int(pow(base, i));
		i++;
		n = n / 10;
	}
	cout << ans << endl;
}

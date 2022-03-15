Print the following pattern for the given number of rows.
Pattern for N = 4
   1
  212
 32123
4321234
Input format : N (Total no. of rows)

Output format : Pattern in N lines

Sample Input :
5
Sample Output :
        1
      212
    32123
  4321234
543212345
        
// Code
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 1;
	while(i <= n) {
		int spaces = 1;
		while(spaces <= n - i) {
			cout << " ";
			spaces++;
		}
		int j = 1;
		int val = i;
		while(j <= 2 * i - 1) {
			cout << val;
			if(j < i) {
				val--;
			} else {
				val++;
			}
			j++;
		}
		cout << endl;
		i++;
	}
}

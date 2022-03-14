Print the following pattern
Pattern for N = 4


The dots represent spaces.



Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input :
5
Sample Output :


The dots represent spaces.

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
			spaces = spaces + 1;
		}
		int j = 1;
		int k = i;
		while(j <= i) {
			cout << k;
			j = j + 1;
			k = k + 1;
		}
		cout << endl;
		i = i + 1;
	}
}

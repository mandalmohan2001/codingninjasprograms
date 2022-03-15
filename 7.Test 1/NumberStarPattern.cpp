Print the following pattern for given number of rows.
Input format :

Line 1 : N (Total number of rows)

Sample Input :
   5
Sample Output :
1234554321
1234**4321
123****321
12******21
1********1

// Code
#include <iostream> 
using namespace std;

int main() {
	int n;
	cin >> n;
	int i = n;
	while(i >= 1) {
		int j = 1;
		while(j <= i) {
			cout << j;
			j++;
		}
		int k = 1;
		while(k <= n - i) {
			cout << "*";
			k++;
		}
		k = 1;
		while(k <= n - i) {
			cout << "*";
			k++;
		}
		j = i;
		while(j >= 1) {
			cout << j;
			j--;
		}
		cout << endl;
		i--;
	}
}

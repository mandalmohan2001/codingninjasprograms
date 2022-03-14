#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter n" << endl;
	cin >> n;

	int i = 1;
	int val = 1;
	while(i <= n) {
		int spaces = 1;
		while(spaces <= n - i) {
			cout << " ";
			spaces = spaces + 1;
		}
		int j = 1;
		while(j <= i) {
			cout << val;
			j = j + 1;
			val = val + 1;
		}
		cout << endl;
		i = i + 1;
	}
}

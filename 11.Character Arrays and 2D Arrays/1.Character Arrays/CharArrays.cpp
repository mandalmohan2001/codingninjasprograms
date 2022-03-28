#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]) {
	int i = 0, j = strlen(str) - 1;
	while(i <= j) {
		if(str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	int size = 1e6;
	char str[size];
	cin >> str;
	cout << (checkPalindrome(str) ? "true" : "false");	
	return 0;
}

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.
Input Format :
 String S
Output Format :
Updated string
Constraints :
1 <= Length of string S <= 10^6
Sample Input :
abc def g hi
Sample Output :
abcdefghi

// Code
#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
	int i = 0;
	while(input[i] != '\0') {
		if(input[i] == ' ') {
			int j;
			for(j = i + 1; input[j] != '\0'; j++) {
				input[j - 1] = input[j];
			}
			input[j - 1] = '\0';
		} else {
			i++;
		}
	}
}

int main() {
	char input[1000000];
	cin.getline(input, 1000000);
	trimSpaces(input);
	cout << input << endl;
	return 0;
}

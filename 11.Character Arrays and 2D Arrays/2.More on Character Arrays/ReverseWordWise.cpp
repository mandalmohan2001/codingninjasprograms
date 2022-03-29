Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always

// Code
#include <iostream>
using namespace std;

void reverse(char input[], int start, int end) {
	while(start < end) {
		char temp = input[start];
		input[start] = input[end];
		input[end] = temp;
		start++;
		end--;
	}
}

int length(char input[]) {
	int count = 0;
	for(int i = 0; input[i] != '\0'; i++) {
		count++;
	}
	return count;
}

void reverseStringWordWise(char input[]) {
	int len = length(input);
	int start = 0, end = 0;
	for(int i = 0; i < len; i++) {
		if(input[i] == ' ') {
			end = i - 1;
			reverse(input, start, end);
			start = i + 1;
		}
	}
	reverse(input, start, len - 1);
	reverse(input, 0, len - 1);
}

int main() {
	char input[1000];
	cin.getline(input, 1000);
	reverseStringWordWise(input);
	cout << input << endl;	
	return 0;
}

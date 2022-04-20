Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

// Code
#include <iostream>
using namespace std;

void printAllPossibleCodes(string input, string output) {
	if(input.empty()) {
		cout << output << endl;
		return;
	}

	if(input.size() >= 2) {
		int num1 = (input[0] - '0');
		printAllPossibleCodes(input.substr(1), output + char(num1 + 'a' - 1));
		int num2 = (input[0] - '0') * 10 + (input[1] - '0');
		if(num2 >= 10 && num2 <= 26) {
			printAllPossibleCodes(input.substr(2), output + char(num2 + 'a' - 1));
		}
	} else {
		int num1 = (input[0] - '0');
		printAllPossibleCodes(input.substr(1), output + char(num1 + 'a' - 1));
	}
}

void printAllPossibleCodes(string input) {
	string output = "";
	printAllPossibleCodes(input, output);
}

int main() {
	string input;
	cin >> input;

	printAllPossibleCodes(input);	
	return 0;
}

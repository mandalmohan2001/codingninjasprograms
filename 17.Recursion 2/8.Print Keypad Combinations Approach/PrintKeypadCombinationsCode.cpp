Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

// Code
#include <iostream>
using namespace std;

void printKeypad(int num, string output) {
	// Base case  
	if(num == 0) {
		cout << output << endl;
		return;
	}

	int rem = num % 10;
	num = num / 10;
	string input;
	switch(rem) {
		case 2: input = "abc";
			break;
		case 3: input = "def";
			break;
		case 4: input = "ghi";
			break;
		case 5: input = "jkl";
			break;
		case 6: input = "mno";
			break;
		case 7: input = "pqrs";
			break;
		case 8: input = "tuv";
			break;
		case 9: input = "wxyz";
			break;
	}
	if(input.size() == 3) {
		printKeypad(num, input[0] + output);
		printKeypad(num, input[1] + output);
		printKeypad(num, input[2] + output);
	} else {
		printKeypad(num, input[0] + output);
		printKeypad(num, input[1] + output);
		printKeypad(num, input[2] + output);
		printKeypad(num, input[3] + output);
	}
}

void printKeypad(int num) {
	string output = "";
	printKeypad(num, output);
}

int main() {
	int num;
	cin >> num;

	printKeypad(num);

	return 0;
}

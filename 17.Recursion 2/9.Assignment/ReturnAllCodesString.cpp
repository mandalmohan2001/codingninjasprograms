Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
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
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    // Base case  
    if(input.empty()) {
    	output[0] = "";
    	return 1;
    }
    string smallOutput1[10000], smallOutput2[10000];
    int size1 = 0, size2 = 0;
    if(input.size() >= 2) {
    	size1 = getCodes(input.substr(1), smallOutput1);
    	size2 = getCodes(input.substr(2), smallOutput2);
    	int num1 = (input[0] - '0');
    	int row = 0;
    	for(int i = 0; i < size1; i++) {
    		output[row] = char(num1 + 'a' - 1) + smallOutput1[i];
    		row++;
    	}
    	int num2 = (input[0] - '0') * 10 + (input[1] - '0');
    	if(num2 >= 10 && num2 <= 26) {
    		for(int i = 0; i < size2; i++) {
    			output[row] = char(num2 + 'a' - 1) + smallOutput2[i];
    			row++;
    		}
    	}
    	return row;
    } else {
    	size1 = getCodes(input.substr(1), smallOutput1);
    	int num1 = (input[0] - '0');
    	int row = 0;
    	for(int i = 0; i < size1; i++) {
    		output[row] = char(num1 + 'a' - 1) + smallOutput1[i];
    		row++;
    	}
    	return row;
    }
}

int main() {
	string input;
	cin >> input;

	string output[10000];
	int count = getCodes(input, output);
	for(int i = 0; i < count && i < 10000; i++) {
		cout << output[i] << endl;
	}	
	return 0;
}

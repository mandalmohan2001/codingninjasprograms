Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba

// Code
#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]) {
	if(input.empty()) {
		output[0] = "";
		return 1;
	}
	int row = 0;
	for(int i = 0; i < input.size(); i++) {
		string smallOutput[10000] = {};
		string newInput = "";
		for(int j = 0; j <= i - 1; j++) {
			newInput = newInput + input[j];
		}
		for(int j = i + 1; j < input.size(); j++) {
			newInput = newInput + input[j];
		}
		int size = returnPermutations(newInput, smallOutput);
		for(int j = 0; j < size; j++) {
			output[row] = input[i] + smallOutput[j];
			row++;
		}
	}
	return row;
}

int main() {
	string input;
	cin >> input;
	string output[10000];
	int count = returnPermutations(input, output);
	for(int i = 0; i < count && i < 10000; i++) {
		cout << output[i] << endl;
	}	
	return 0;
}

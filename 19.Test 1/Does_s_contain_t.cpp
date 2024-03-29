Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
true or false
Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true
Sample Input 2 :
abcde
aeb
Sample Output 2 :
false
  
// Code
#include <iostream>
using namespace std;

bool checksequence(char large[], char *small) {
	if(small[0] == '\0' && large[0] != '\0') {
		return true;
	} else if(small[0] != '\0' && large[0] == '\0') {
		return false;
	} else if(large[0] == '\0' && small[0] == '\0') {
		return true;
	}

	int i = 0;
	for(;large[i] != '\0'; i++) {
		if(large[i] == small[0]) {
			break;
		}
	}
	if(large[i]=='\0') {
		return false;
	}

	return checksequence(large + i + 1, small + 1);
}

int main() {
	char large[10000];
	char small[10000];
	cin >> large;
	cin >> small;
	bool x = checksequence(large, small);

	if(x) {
		cout << "true";
	} else {
		cout << "false";
	}
	return 0;
}

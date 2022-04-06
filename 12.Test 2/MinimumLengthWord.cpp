Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.
Input Format :
String S
Output Format :
Minimum length word
Constraints :
1 <= Length of String S <= 10^5
Sample Input 1 :
this is test string
Sample Output 1 :
is
Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a

// Code
#include <iostream>
using namespace std;

void minLengthWord(char input[], char output[]) {
	int start = 0, end = 0;
	int minLength = 0; 
	string minLengthString = input;
	int i;
	for(i = 0; input[i] != '\0'; i++) {
		if(input[i] == ' ') {
			string s = "";
			end = i-1;
			for(int j = start; j <= end; j++) {
				s = s + input[j];
			}
			if(s.size() < minLengthString.size()) {
				minLengthString = s;
			}
			start = i + 1;
		}
	}
	string s = "";
	for(int j = start; j <= i-1; j++) {
		s = s + input[j];
	}
	if(s.size() < minLengthString.size()) {
		minLengthString = s;
	}
	for(i = 0; i < minLengthString.size(); i++) {
		output[i] = minLengthString[i];
	}
	output[i] = '\0';
}

int main() {
	char ch[10000], output[10000];
  	cin.getline(ch, 10000);
  	minLengthWord(ch, output);
  	cout << output << endl;
	return 0;
}

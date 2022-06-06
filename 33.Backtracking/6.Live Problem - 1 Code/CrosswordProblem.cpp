Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

// Code
#include <bits/stdc++.h>
#define N 10
using namespace std;

bool isValidVertical(char cross[N][N], int row, int col, string word) {
	int j = row;
	for(int i = 0; i < word.length(); i++) {
		if(j > 9) {
			return false;
		}
		if(cross[j][col] == '+') {
			return false;
		}
		if(cross[j][col] != '-' && (cross[j][col] != word[i])) {
			return false;
		}
		if(cross[j][col] == '-' || cross[j][col] == word[i]) {
			j++;
		}
	}
	return true;
}

bool isValidHorizontal(char cross[N][N], int row, int col, string word) {
	int j = col;
	for(int i = 0; i < word.length(); i++) {
		if(j > 9) {
			return false;
		}
		if(cross[row][j] == '+') {
			return false;
		}
		if(cross[row][j] != '-' && (cross[row][j] != word[i])) {
			return false;
		}
		if(cross[row][j] == '-' || cross[row][j] == word[i]) {
			j++;
		}
	}
	return true;
}

void setVertical(char cross[N][N], int row, int col, vector<bool> &helper, string word) {
	int j = row;
	for(int i = 0; i < word.length(); i++) {
		if(cross[j][col] == '-') {
			cross[j][col] = word[i];
			helper.push_back(true);
		} else {
			helper.push_back(false);
		}
		j++;
	}
}

void resetVertical(char cross[N][N], int row, int col, vector<bool> &helper) {
	int j = row;
	for(int i = 0; i < helper.size(); i++) {
		if(helper[i]) {
			cross[j][col] = '-';
		} 
		j++;
	}
}

void setHorizontal(char cross[N][N], int row, int col, vector<bool> &helper, string word) {
	int j = col;
	for(int i = 0; i < word.length(); i++) {
		if(cross[row][j] == '-') {
			cross[row][j] = word[i];
			helper.push_back(true);
		} else {
			helper.push_back(false);
		}
		j++;
	}
}

void resetHorizontal(char cross[N][N], int row, int col, vector<bool> &helper) {
	int j = col;
	for(int i = 0; i < helper.size(); i++) {
		if(helper[i]) {
			cross[row][j] = '-';
		}
		j++;
	}
}

bool crossword(char cross[N][N], vector<string> words, int index) {
	// Base case is if index becomes == words.size(), then print the crossword
	if(index >= words.size()) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cout << cross[i][j];
			}
			cout << endl;
		}
		return true;
	}
	for(int row = 0; row < N; row++) {
		for(int col = 0; col < N; col++) {
			if(cross[row][col] == '-' || (cross[row][col] == words[index][0])) {
				if(isValidVertical(cross, row, col, words[index])) {
					vector<bool> helper;
					setVertical(cross, row, col, helper, words[index]);
					if(crossword(cross, words, index + 1)) {
						return true;
					}
					resetVertical(cross, row, col, helper);
				}
				if(isValidHorizontal(cross, row, col, words[index])) {
					vector<bool> helper;
					setHorizontal(cross, row, col, helper, words[index]);
					if(crossword(cross, words, index + 1)) {
						return true;
					}
					resetHorizontal(cross, row, col, helper);
				}
			}
		}
	}
}

int main() {
	char cross[N][N];
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) {
			cross[i][j] = s[j];
		}
	}

	string s;
	cin >> s;
	vector<string> words;
	for(int i = 0; i < s.length(); i++) {
		int j = i;
		while(s[j] != ';' && j < s.length()) {
			j++;
		}
		words.push_back(s.substr(i, j - i));
		i = j;
	}
	bool x = crossword(cross, words, 0);
}

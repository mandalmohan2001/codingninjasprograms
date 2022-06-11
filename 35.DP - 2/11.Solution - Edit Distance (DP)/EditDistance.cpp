#include <iostream>
#include <cmath>
using namespace std;

// Dynamic Programming
int editDistance_DP(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n + 1];
	}

	// Fill 1st row 
	for(int j = 0; j <= n; j++) {
		output[0][j] = j;
	}

	// Fill 1st column
	for(int i = 0; i <= m; i++) {
		output[i][0] = i;
	}

	// Fill remaining cells
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[m - i] == t[n - j]) {
				output[i][j] = output[i - 1][j - 1];
			} else {
				int a = output[i - 1][j];
				int b = output[i][j - 1];
				int c = output[i - 1][j - 1];
				output[i][j] = min(a, min(b, c)) + 1;
			}
		}
	}

	return output[m][n];
}

// Memoization
int editDistance_mem(string s, string t, int **output) {
	int m = s.size();
	int n = t.size();

	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	// Recursive calls
	if(s[0] == t[0]) {
		ans = editDistance_mem(s.substr(1), t.substr(1), output);
	} else {
		// insert
		int x = editDistance_mem(s.substr(1), t, output) + 1;
		// Delete 
		int y = editDistance_mem(s, t.substr(1), output) + 1;
		// Replace
		int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

		ans = min(x, min(y, z));
	}

	// Save the ans
	output[m][n] = ans;

	// Return the ans 
	return ans;
}

int editDistance_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **ans = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		ans[i] = new int[n + 1];
		for(int j = 0; j <= n; j++) {
			ans[i][j] = -1;
		}
	}
	return editDistance_mem(s, t, ans);
}

// Brute force
int editDistance(string s, string t) {
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		return max(s.size(), t.size());
	}

	// Recursive calls
	if(s[0] == t[0]) {
		return editDistance(s.substr(1), t.substr(1));
	} else {
		// insert
		int x = editDistance(s.substr(1), t) + 1;
		// Delete 
		int y = editDistance(s, t.substr(1)) + 1;
		// Replace
		int z = editDistance(s.substr(1), t.substr(1)) + 1;

		return min(x, min(y, z));
	}
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << editDistance_DP(s, t) << endl;
	cout << editDistance_mem(s, t) << endl;
	cout << editDistance(s, t) << endl;
	return 0;
}

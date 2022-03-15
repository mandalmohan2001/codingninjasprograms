Write a program to count and print the total number of characters (lowercase english alphabets only), digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
Print count of characters, count of digits and count of white spaces respectively (separated by space).
Input Format :
A stream of characters terminated by '$'
Output Format :
3 integers i.e. count_of_characters count_of_digits count_of_whitespaces (separated by space)
Sample Input :
abc def4 5$
Sample Output :
6 2 2
Sample Output Explanation :
Number of characters : 6 (a, b, c, d, e, f)
Number of digits : 2 (4, 5)
Number of white spaces : 2 (one space after abc and one newline after 4)

// Code
#include <iostream>
using namespace std;

int main() {
	char c;
	c = cin.get();
	int countAlphabets = 0, countDigits = 0, countWhitespaces = 0;
	while(c != '$') {
		if(c >= 'a' && c <= 'z') {
			countAlphabets++;
		} else if(c >= '0' && c <= '9') {
			countDigits++;
		} else {
			countWhitespaces++;
		}
		c = cin.get();
	}
	cout << countAlphabets << " " << countDigits << " " << countWhitespaces << endl;
}
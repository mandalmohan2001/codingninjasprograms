Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
  
// Code
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    bool search(TrieNode *root, string word) {
        // Base case 
        if(word.size() == 0) {
            return root -> isTerminal;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            return false;
        }
        
        // Recursive call
        return search(child, word.substr(1));
    }
    
    bool search(string word) {
        return search(root, word);
    }
    
    bool isPalindrome(string word) {
        int front = 0;
        int back = word.size() - 1;
        
        while(front < back) {
            if(word[front] == word[back]) {
                front++;
                back--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i = 0; i < words.size(); i++) {
            add(words[i]); 	// add all words to the Trie
        }
        
        // Note here we will have no problem when the words are of odd length
        // However a corner case may arise when we have words of even length
        // Eg : abcm cba  or abc mcba;
        // The last elseif is used to address these cases
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            if(search(word)) { // Checking for any two words which can be joined to make a palindrome
                return true;
            } else if(isPalindrome(words[i])) { // Checking any word itself is a palindrome
                return true;
            } else if(search(word.substr(0, word.size() - 1)) || search(word.substr(1))) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
	Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
	return 0;
}

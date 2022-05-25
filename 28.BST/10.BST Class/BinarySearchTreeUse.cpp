#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BST *tree = new BST();
	int choice, input, q;
	cin >> q;
	while(q--) {
		cin >> choice;
		switch(choice) {
			case 1:
				cin >>  input;
				tree -> insert(input);
				break;
			case 2:
				cin >> input;
				tree -> deleteData(input);
				break;
			case 3:
				cin >> input;
				cout << ((tree -> hasData(input)) ? "true\n" : "false\n");
				break;
			default:
				tree -> printTree();
				break;
		}
	}
	return 0;
}

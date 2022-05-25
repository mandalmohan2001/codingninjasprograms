#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTree();
	b.deleteData(10);
	b.deleteData(100);
	b.printTree();
	return 0;
}

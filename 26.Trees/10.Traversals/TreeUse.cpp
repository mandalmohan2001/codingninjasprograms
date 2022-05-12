#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front -> data << endl;
		int numChild;
		cin >> numChild;
		for(int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front -> data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for(int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root -> children.push_back(child);
	}
	return root;
}

void printTreeLevelWise(TreeNode<int>* root) {
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front -> data << ":";
		for(int i = 0; i < front -> children.size(); i++) {
			cout << front -> children[i] -> data << ",";
			pendingNodes.push(front -> children[i]);
		}
		cout << endl;
	}

}

void printTree(TreeNode<int>* root) {
	if(root == NULL) { // Edge case
		return;
	}

	cout << root -> data << ":";
	for(int i = 0; i < root-> children.size(); i++) {
		cout << root -> children[i] -> data << ",";
	}
	cout << endl;
	for(int i = 0; i < root -> children.size(); i++) {
		printTree(root -> children[i]);
	}
}

void printAtLevelK(TreeNode<int>* root, int k) {
	if(root == NULL) { // edge case
		return;
	}
	if(k == 0) {
		cout << root -> data << endl;
		return;
	}
	for(int i = 0; i < root -> children.size(); i++) {
		printAtLevelK(root -> children[i], k - 1);
	}
}

int numNodes(TreeNode<int>* root) {
	if(root == NULL) { // edge case
		return 0;
	}
	int ans = 1;
	for(int i = 0; i < root -> children.size(); i++) {
		ans += numNodes(root -> children[i]);
	}
	return ans;
}

void preorder(TreeNode<int>* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> data << " ";
	for(int i = 0; i < root -> children.size(); i++) {
		preorder(root -> children[i]);
	}
}

// 10 3 20 30 40 2 50 60 0 0 0 0 
int main() {

	/*
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root -> children.push_back(node1);
	root -> children.push_back(node2);
	*/

	TreeNode<int>* root = takeInputLevelWise();
	//printTreeLevelWise(root);
	printAtLevelK(root, 1);
	preorder(root);
	// TODO delete the tree  
	return 0;
}

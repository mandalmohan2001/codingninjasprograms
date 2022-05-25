#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
class BST {
	BinaryTreeNode<int>* root;

	public :
		BST() {
			root = NULL;
		}

		~BST() {
			delete root;
		}

		private :
			void printTree(BinaryTreeNode<int>* node) {
				if(node == NULL) {
					return;
				}
				cout << node -> data << ":";
				if(node -> left != NULL) {
					cout << "L:" << node -> left -> data << ",";
				}
				if(node -> right != NULL) {
					cout << "R:" << node -> right -> data;
				}
				cout << endl;
				printTree(node -> left);
				printTree(node -> right);
			}

		public :
			void printTree() {
				printTree(root);
			}

		private :
			BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* node, int data) {
				if(node == NULL) {
					return NULL;
				}
				if(data < node -> data) {
					node -> left = deleteData(node -> left, data);
				} else if(data > node -> data) {
					node -> right = deleteData(node -> right, data);
				} else {
					if(node -> left == NULL && node -> right == NULL) {
						delete node;
						return NULL;
					} else if(node -> left != NULL && node -> right == NULL) {
						BinaryTreeNode<int>* temp = node -> left;
						node -> left = NULL;
						delete node;
						return temp;
					} else if(node -> left == NULL && node -> right != NULL) {
						BinaryTreeNode<int>* temp = node -> right;
						node -> right = NULL;
						delete node;
						return temp;
					} else {
						BinaryTreeNode<int>* minNode = node -> right;
						while(minNode -> left != NULL) {
							minNode = minNode -> left;
						}
						int rightMin = minNode -> data;
						node -> data = rightMin;
						node -> right = deleteData(node -> right, rightMin);
						return node;
					}
				}
			}

		public :
			void deleteData(int data) {
				root = deleteData(root, data);
			}

		private :
			BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) {
				if(node == NULL) {
					BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
					return newNode;
				}

				if(data <= node -> data) {
					node -> left = insert(node -> left, data);
				} else {
					node -> right = insert(node -> right, data);

				}
				return node;
			}

		public :
			void insert(int data) {
				root = insert(root, data);
			}

		private :
			bool hasData(int data, BinaryTreeNode<int>* node) {
				if(node == NULL) {
					return false;
				}

				if(node -> data == data) {
					return true;
				} else if(data < node -> data) {
					return hasData(data, node -> left);
				} else {
					return hasData(data, node -> right);
				}
			}
			
		public :
			bool hasData(int data) {
				return hasData(data, root);
			}
};

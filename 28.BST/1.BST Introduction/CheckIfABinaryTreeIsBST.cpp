Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
The first and only line of output contains either true or false.
Constraints :
Time Limit: 1 second
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false


// Code
pair<bool, pair<int, int>> isBSTHelper(BinaryTreeNode<int>* root) {
	if(root == NULL) {
		pair<bool, pair<int, int>> p;
		pair<int, int> p2;
		p2.first = INT_MAX;
		p2.second = INT_MIN;
		p.first = true;
		p.second = p2;
		return p;
	}

	pair<bool, pair<int, int>> left = isBSTHelper(root -> left);
	pair<bool, pair<int, int>> right =  isBSTHelper(root -> right);

	pair<int, int> p1 = left.second;
	pair<int, int> p2 = right.second;

	int minimum = min(root -> data, min(p1.first, p2.first));
	int maximum = max(root -> data, max(p1.second, p2.second));

	bool isBSTfinal = (root -> data > p1.second) && (root -> data < p2.first) && left.first && right.first;

	pair<bool, pair<int, int>> ans;
	ans.first = isBSTfinal;
	pair<int, int> p3;
	p3.first = minimum;
	p3.second = maximum;
	ans.second = p3;
	return ans;
}

bool isBST(BinaryTreeNode<int>* root) {
	// Write your code here
    pair<bool, pair<int, int>> p = isBSTHelper(root);
    return p.first;
}

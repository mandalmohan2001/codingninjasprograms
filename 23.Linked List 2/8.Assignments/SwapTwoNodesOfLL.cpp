You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
  
// Code
#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int data) {
			this -> data = data;
			this -> next = NULL;
		}
};

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail -> next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head) {
	Node *temp = head;
	while(temp != NULL) {
		cout << temp -> data << " ";
		temp =  temp -> next;
	}
	cout << endl;
}

Node *swapNodes(Node *head, int i, int j) {
	if(i == j) {
		return head;
	}
	if(i > j) {
		int temp = i;
		i = j;
		j = temp;
	}
	if(i == 0 && j == 1) {
		Node *current1 = head, *prev1 = NULL;
		Node *current2 = current1 -> next, *prev2 = current1;
		head = current2;
		prev2 -> next = current1;
		current1 -> next = current2 -> next;
		current2 -> next = prev2;
		return head;
	}
	if(i == 0 && (j - i == 2)) {
		Node *current1 = head, *prev1 = NULL;
		Node *current2 = head, *prev2 = NULL;
		for(int index = 1; index <= j; index++) {
			prev2 = current2;
			current2 = current2 -> next;
		}
		head = current2;
		prev2 -> next = current1;
		current1 -> next = current2 -> next;
		current2 -> next = prev2;
		return head;
	}
	if(i == 0 && (j - i > 2)) {
		Node *current1 = head, *prev1 = NULL;
		Node *current2 = head, *prev2 = NULL;
		for(int index = 1; index <= j; index++) {
			prev2 = current2;
			current2 = current2 -> next;
		}
		Node *temp1 = current1 -> next;
		Node *temp2 = current2 -> next;
		head = current2;
		current2 -> next = temp1;
		prev2 -> next = current1;
		current1 -> next = temp2;
		return head;
	}
	if(j - i == 1) {
		Node *current1 = head, *prev1 = NULL;
		for(int index = 1; index <= i; index++) {
			prev1 = current1;
			current1 = current1 -> next;
		}
		Node *current2 = current1 -> next, *prev2 = current1;
		prev1 -> next = current2;
		prev2 -> next = current1;
		current1 -> next = current2 -> next;
		current2 -> next = prev2;
		return head;
	}
	if(j - i == 2) {
		Node *current1 = head, *prev1 = NULL;
		for(int index = 1; index <= i; index++) {
			prev1 = current1;
			current1 = current1 -> next;
		}
		Node *current2 = current1 -> next, *prev2 = current1;
		for(int index = i + 1; index <= j; index++) {
			prev2 = current2;
			current2 = current2 -> next;
		}
		prev1 -> next = current2;
		prev2 -> next = current1;
		current1 -> next = current2 -> next;
		current2 -> next = prev2;
		return head;
	}
	if(j - i > 2) {
		Node *current1 = head, *prev1 = NULL;
		for(int index = 1; index <= i; index++) {
			prev1 = current1;
			current1 = current1 -> next;
		}
		Node *current2 = current1 -> next, *prev2 = current1;
		for(int index = i + 1; index <= j; index++) {
			prev2 = current2;
			current2 = current2 -> next;
		}
		Node *temp1 = current1 -> next;
		Node *temp2 = current2 -> next;
		prev1 -> next = current2;
		current2 -> next = temp1;
		prev2 -> next = current1;
		current1 -> next = temp2;
		return head;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}

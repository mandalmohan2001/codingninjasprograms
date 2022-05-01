Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
  
// Code
#include <iostream>
using namespace std;

class Node {
	public :
		int data;
		Node *next;
		Node(int data) {
			this -> data = data;
			this -> next = NULL;
		}
};

Node* takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
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
		temp = temp -> next;
	}
	cout << endl;
}

Node* merge(Node *head1, Node *head2) {
	if(head1 == NULL && head2 == NULL) {
		return NULL;
	}
	Node *start = NULL;
	Node *end = NULL;
	while(head1 != NULL && head2 != NULL) {
		if(head1 -> data < head2 -> data) {
			if(start == NULL) {
				start = head1;
				end = head1;
				head1 = head1 -> next;
			} else {
				end -> next = head1;
				end = head1;
				head1 = head1 -> next;
			}
		} else {
			if(start == NULL) {
				start = head2;
				end = head2;
				head2 = head2 -> next;
			} else {
				end -> next = head2;
				end = head2;
				head2 = head2 -> next;
			}
		}
	}
	if(head1 == NULL) {
		if(start == NULL) {
			start = head2;
		} else {
			end -> next = head2;
		}
	}
	if(head2 == NULL) {
		if(start == NULL) {
			start = head1;
		} else {
			end -> next = head1;
		}
	}
	return start;
}

Node* mergeSort(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}
	Node *slow = head;
	Node *fast = head -> next;
	while(fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	Node *temp = slow -> next;
	slow -> next = NULL;
	Node *head1 = mergeSort(head);
	Node *head2 = mergeSort(temp);
	Node *head3 = merge(head1, head2);
	return head3;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}
	return 0;
}

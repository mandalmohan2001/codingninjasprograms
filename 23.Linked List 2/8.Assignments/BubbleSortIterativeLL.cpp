Given a singly linked list of integers, sort it using 'Bubble Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
  
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

int length(Node *head) {
	Node *temp = head;
	int count = 0;
	while(temp != NULL) {
		temp = temp -> next;
		count++;
	}
	return count;
}

Node* bubbleSort(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}
	int size = length(head);
	for(int i = 0; i < size - 1; i++) {
		Node *current1 = head, *prev1 = NULL;
		Node *current2 = current1 -> next, *prev2 = current1;
		while(current2 != NULL) {
			if(current1 -> data > current2 -> data) {
				if(prev1 == NULL) {
					head = current2;
					prev2 -> next = current1;
					current1 -> next = current2 -> next;
					current2 -> next = prev2;

					prev1 = current2;
					current2 = current1 -> next;
				} else {
					prev1 -> next = current2;
					prev2 -> next = current1;
					current1 -> next = current2 -> next;
					current2 -> next = prev2;

					prev1 = current2;
					current2 = current1 -> next;
				}
			} else {
				prev1 = current1;
				current1 = current1 -> next;
				prev2 = current2;
				current2 = current2 -> next;
			}
		}
	}
	return head;
}

int main() {
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
	return 0;
}

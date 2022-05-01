#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput_Better() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}
		cin >> data;
	}
	return head;
}

Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;
	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}
	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}

Node* deleteNode(Node *head, int i) {
	int count = 0; 
	Node *temp = head;
	if(i == 0) {
		head = temp -> next;
		delete temp;
		return head;
	}
	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		Node *b = a -> next;
		temp -> next = b;
		delete a;
	}
	return head;
}

void print(Node *head) {
	// Node *temp = head;
	
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}

	/*
	temp = head;
	while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	*/
}

int main() {
	
	Node *head = takeInput_Better();
	print(head);
	/*
	int i, data;
	cin >> i >> data;
	head = insertNode(head, i, data);
	print(head);
	*/
	int i;
	cin >> i;
	head = deleteNode(head, i);
	print(head);

	/*
	// Statically 
	Node n1(1);
	Node *head = &n1;

	Node n2(2);

	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	print(head);

	print(head);
	*/

	/*
	n1.next = &n2;

	cout << n1.data << " " << n2.data << endl;	
	
	// Dynamically  
	Node *n3 = new Node(10);
	Node *head = n3;

	Node *n4 = new Node(20);
	n3 -> next = n4;
	*/

	return 0;
}

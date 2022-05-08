Given a Singly Linked List of integers, delete all the alternate nodes in the list.
Example:
List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> null
Alternate nodes will be:  20, 40, and 60.

Hence after deleting, the list will be:
Output: 10 -> 30 -> 50 -> null
Note :
The head of the list will remain the same. Don't need to print or return anything.
Input format :
The first and the only line of input will contain the elements of the Singly Linked List separated by a single space and terminated by -1.
Output Format :
The only line of output will contain the updated list elements.
Input Constraints:
1 <= N <= 10 ^ 6.
Where N is the size of the Singly Linked List

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 -1
Sample Output 1:
1 3 5
Explanation of Sample Input 1:
2, 4 are alternate nodes so we need to delete them 
Sample Input 2:
10 20 30 40 50 60 70 -1
Sample Output 2:
10 30 50 70 
  
// Code
#include <iostream>
using namespace std;

class Deque {
	int *deq;
	int front;
	int rear;
	int si;

	public :
		Deque(int size) {
			deq = new int[size];
			si = size;
			front = -1;
			rear = -1;
		}

		void insertFront(int ele) {
			if(front == -1 && rear == -1) {
				front = 0;
				rear = 0;
				deq[front] = ele;
				return;
			}
			if(front == 0 && rear == si -1 || rear == front - 1) {
				cout << (-1) << endl;
				return;
			}
			if(front == 0) {
				front = si - 1;
				deq[front] = ele;
			} else {
				front--;
				deq[front] = ele;
			}
		}

		void insertRear(int ele) {
			if(front == -1 && rear == -1) {
				front = 0;
				rear = 0;
				deq[rear] = ele;
				return;
			}
			if((rear + 1) % si == front) {
				cout << (-1) << endl;
				return;
			}
			rear = (rear + 1) % si;
			deq[rear] = ele;
		}

		void deleteFront() {
			if(front == -1 && rear == -1) {
				cout << (-1) << endl;
				return;
			}
			if(front == rear) {
				front = -1;
				rear = -1;
				return;
			}
			front = (front + 1) % si;
		}

		void deleteRear() {
			if(front == -1 && rear == -1) {
				cout << (-1) << endl;
				return;
			}
			if(front == rear) {
				front = -1;
				rear = -1;
				return;
			}
			if(rear == 0) {
				rear = si - 1;
			} else {
				rear--;
			}
		}

		int getFront() {
			if(front == -1 && rear == -1) {
				return -1;
			}
			return deq[front];
		}

		int getRear() {
			if(front == -1 && rear == -1) {
				return -1;
			}
			return deq[rear];
		}
};

int main() {
	Deque dq(10);
	int choice, input;
	while(true) {
		cin >> choice;
		switch(choice) {
			case 1:
				cin >> input;
				dq.insertFront(input);
				break;
			case 2:
				cin >> input;
				dq.insertRear(input);
				break;
			case 3:
				dq.deleteFront();
				break;
			case 4:
				dq.deleteRear();
				break;
			case 5:
				cout << dq.getFront() << endl;
				break;
			case 6:
				cout << dq.getRear() << endl;
				break;
			default:
				return 0;
		}
	}	
	return 0;
}

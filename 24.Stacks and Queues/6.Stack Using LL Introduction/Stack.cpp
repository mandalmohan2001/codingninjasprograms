template <typename T>
class Node {
	public :
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			this -> next = NULL;
		}
};

template <typename T>
class Stack {
	Node<T> *head;
	int size;    // number of elements present in stack   

	public :
		Stack() {
			head = NULL;
			size = 0;
		}

		int getSize() {
			return size;
		}

		bool isEmpty() {
			return head == NULL;
		}

		void push(T element) {
			Node<T> *newNode = new Node<T>(element);
			if(head == NULL) {
				head = newNode;
				size++;
			} else {
				newNode -> next = head;
				head = newNode;
				size++;
			}
		}

		T pop() {
			if(head == NULL) {
				cout << "Stack is empty" << endl;
				return 0;
			}
			T ans = head -> data;
			Node<T> *temp = head;
			head = head -> next;
			delete temp;
			size--;
			return ans;
		}

		T top() {
			if(head == NULL) {
				cout << "Stack is empty" << endl;
				return 0;
			}
			return head -> data;
		}
};

#include<iostream>
using namespace std;

class Node{
	public:
		Node* prev, *next;
		int key;
};

class LinkedList {
	public:
		Node* N;
		Node* head;
		
		Node* Search(int k) {
			N = this->head;
				while (N != NULL && N->key != k)
					{
						N = N->next;
					}
				return N;
		}

		void insert(Node* n) {
			n->next = head;
				if (head != NULL)
					{
						head->prev = n;
					}
				head = n;
			n->prev = NULL;
		}

		void Delete(Node* n) {
			if (n->prev != NULL)
				n->prev->next = n->next;
			else
				head = n->next;
			if (n->next != NULL)
				n->next->prev = n->prev;
		}

};

int main() {
	LinkedList L = LinkedList();
	Node* a = new Node();
	Node* b = new Node();
	b->key = 6;
	a->key = 5;
	L.insert(b);
	L.insert(a);
	cout << L.head->key << endl;
	cout << L.head->next->key << endl;
	L.Delete(b);
	cout << L.Search(5)->key << endl;
	system("pause");
	return 0;
}
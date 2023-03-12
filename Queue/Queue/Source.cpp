#include<iostream>
using namespace std;

class queue {
public:
	int head, tail;
	int A[1000];
	queue() {
		head = 0;
		tail = 0;
	}
	void enqueue(queue &q, int val) {
		q.A[q.tail] = val;
		q.tail++;
	}
	int deqeue(queue &q) {
		x = q.A[q.head];
		q.head++;
		return x;
	}
private:
	int x;
};

int main() {
	queue q;
	q.enqueue(q, 10);
	q.enqueue(q, 15);
	q.enqueue(q, 20);
	cout << q.deqeue(q) << endl;
	cout << q.deqeue(q) << endl;
	cout << q.deqeue(q) << endl;
	system("pause");
	return 0;
}
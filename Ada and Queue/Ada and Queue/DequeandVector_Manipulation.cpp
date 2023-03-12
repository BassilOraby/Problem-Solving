#include <iostream>
#include <deque>
using namespace std;

int q, x;
bool flag = 0;
char op[50];
deque<int> dq;

int main() {
	scanf_s("%d\n", &q);
	while (q--) {
		scanf_s("%s",op,sizeof(op));
		if (op[0] == 't') {
			scanf_s("%d", &x);
			flag ? dq.push_back(x) : dq.push_front(x);
		}
		else if (op[0] == 'p') {
			scanf_s("%d", &x);
			flag ? dq.push_front(x) : dq.push_back(x);
		}
		else if (op[0] == 'r') {
			flag = !flag;
		}
		else if (op[0] == 'b') {
			if (dq.size() == 0)
				printf("No job for Ada?\n");
			else {
				if (flag)
				{
					printf("%d\n", dq.front());
					dq.pop_front();
				}
				else
				{
					printf("%d\n", dq.back());
					dq.pop_back();
				}
			}
		}
		else if (op[0] == 'f') {
			if (dq.size() == 0)  printf("No job for Ada?\n");
			else {
				if (flag)
				{
					printf("%d\n", dq.back());
					dq.pop_back();
				}
				else
				{
					printf("%d\n", dq.front());
					dq.pop_front();
				}
			}
		}
	}
	system("pause");
	return 0;
}
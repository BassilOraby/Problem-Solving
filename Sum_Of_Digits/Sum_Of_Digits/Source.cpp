#include <iostream>
#include <deque>
#include<string>
using namespace std;

int main() {
	deque <int> dq;
	int s = 0, T;
	string str;
	scanf_s("%d", &T);
	while (T--)
	{
		cin >> str;
		for (size_t i = 0; i < str.length(); i++)
			s += str[i] - '0';
		dq.push_back(s);
		s = 0;
	}
	for (size_t i = 0; i < dq.size(); i++)
		printf("%d\n", dq[i]);
	return 0;
}
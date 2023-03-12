#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, x;
	vector<int>vec;
	queue<int>discarded;
	cin >> n;
	while (n!=0)
	{
		for (int i = n; i >= 1; i--) {
			vec.push_back(i);
		}
		while (vec.size() >= 2)
		{
			discarded.push(vec.back());
			vec.pop_back();
			if (vec.size() == 1)
				break;
			vec.insert(vec.begin(), vec.back());
			vec.pop_back();
		}
		cout << "Discarded cards:";
		x = discarded.size();
		for (int i = 0; i < x; i++) {
			cout << " " << discarded.front();
			discarded.pop();
			if (!discarded.empty())
				cout << ",";
		}
		cout << endl;
		cout << "Remaining card: " << vec.front() << endl;
		vec.clear();
		cin >> n;
	}
	return 0;
}
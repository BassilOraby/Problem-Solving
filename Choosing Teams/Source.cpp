#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
	int n, t = 3, k, x=0, j, y;
	stack<int> st;
	cin >> n >> k;
	while (n--)
	{
		cin >> y;
		st.push(y);
	}
	while (!st.empty())
	{
		if ((st.top() + k) <= 5)
			x++;
		st.pop();
	}
	j = x / t;
	cout << j << endl;
	return 0;
}
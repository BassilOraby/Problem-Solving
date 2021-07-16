#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
using namespace std;
int n, x;
deque<string>rule, dict;
char opts[2] = {'#','0'};

void solve() {
	if (dict.empty())
		return;
	else
	{
		
	}
}

int main() {
	
	while (~(scanf_s("%d",&n)))
	{
		for (int i = 0; i < n; i++)
			cin >> dict[i];
		scanf_s("%d", &x);
		for (int i = 0; i < x; i++)
			cin >> rule[i];
		solve();
	}
}
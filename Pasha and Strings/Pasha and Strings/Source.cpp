#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
const int N = (2 * (1e5)) + 2;

int main() {
	string s;
	int m, a, freq[N] = {}, count = 0;
	cin >> s;
	scanf_s("%d", &m);
	while (m--)
	{
		scanf_s("%d", &a);
		for (int i = a-1; i < (s.length()/2); i++)
			freq[i]++;
	}
	for (int i = 0; i < (s.length()/2); i++)
	{
		if (freq[i] % 2 != 0)
			swap(s[i], s[(s.length() - (i+1))]);
		else
			continue;
	}
	for (int i = 0; i < s.length(); i++)
	{
		printf("%c", s[i]);
	}
	system("pause");
	return 0;
}
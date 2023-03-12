#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;

int main() {
	int n,x,y,k=0;
	char s[140];
	bool flag = true; 
	queue<string> ans;
	stack<char> sequence;
	scanf_s("%d", &n);
	getc(stdin);
	x = n;
	while (n--)
	{
		gets_s(s);
		y = strlen(s);
		for (int j = 0; j <= y-1 ; j++)
		{
			switch (s[j])
			{
			case '(':
				sequence.push(s[j]);
				break;
			case ')':
				if (sequence.empty() || sequence.top() != '(')
				{
					flag = false;
					break;
				}
				else {
					sequence.pop();
					break;
				}
			case '[':
				sequence.push(s[j]);
				break;
			case ']':
				if (sequence.empty() || sequence.top() != '[')
				{
					flag = false;
					break;
				}
				else {
					sequence.pop();
					break;
				}
			default:
				break;
			}
			if (flag == false) {
				ans.push("No");
				while (sequence.empty() == false)
					sequence.pop();
				break;
			}
		}
		if (sequence.empty() && flag) {
			ans.push("Yes");
		}
		if (sequence.empty() == false) {
			ans.push("No");
			while (sequence.empty() == false)
				sequence.pop();
		}
		flag = true;
	}
	for (int g = 0; g < x; g++)
	{
		cout << ans.front() << endl;
		ans.pop();
	}
	return 0;
}
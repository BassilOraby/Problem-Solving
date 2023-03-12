#include <iostream>
#include <sstream> 
#include <cctype>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T, k, space_Counter = 0, a, b, c, d;
	string str, Container;
	vector<int> Cont;
	cout << "Please Enter the number of Test Cases: ";
	cin >> T;
	for (int i = 0; i < T+1; i++)
	{
		getline(cin, str);
		for (int q = 0; q < str.length(); q++)
		{
			if (str[q] != ' ')
			{
				Container += str[q];
				stringstream geek(Container);
				geek >> k;
				space_Counter = 0;
				goto end;
			}
			space_Counter++;
			if (space_Counter >= 2 )
			{
				goto end;
			}
			Cont.push_back(k);
			Container = "";
		end:
			if (q == 3)
			{
				cout << Cont.at(0);
			}
			continue;
		}
	}
	system("pause");
	return 0;
}
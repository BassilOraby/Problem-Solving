#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string s;
	for (int i = 0; i < 10; i++)
	{
		s += (char)(('0' + i) + '\n');
	}
	cout << s;
	system("pause");
	return 0;
}
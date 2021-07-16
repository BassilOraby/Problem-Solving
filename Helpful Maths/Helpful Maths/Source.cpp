#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	char x;
	string s;
	stack<char>ss;
	cin >> s;
	while (s.find('3') != std::string::npos) {
		ss.push('3');
		s.erase(s.find('3'), 1);
		if (s.find('+') != std::string::npos) 
		{
			ss.push('+');
			s.erase(s.find('+'), 1);
		}
	}
	while (s.find('2') != std::string::npos) {
		ss.push('2');
		s.erase(s.find('2'), 1);
		if (s.find('+') != std::string::npos)
		{
			ss.push('+');
			s.erase(s.find('+'), 1);
		}
	}
	while (s.find('1') != std::string::npos) {
		ss.push('1');
		s.erase(s.find('1'), 1);
		if (s.find('+') != std::string::npos)
		{
			ss.push('+');
			s.erase(s.find('+'), 1);
		}
	}
	while (!(ss.empty())){
		x = ss.top();
		cout << x;
		ss.pop();
	}
	return 0;
}
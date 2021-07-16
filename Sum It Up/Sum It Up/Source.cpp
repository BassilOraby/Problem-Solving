#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int i = 123;
	std::string out_string;
	std::stringstream ss;
	ss << i;
	out_string = ss.str();
	cout << out_string << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	bool flag = false;
	string str, word, cont;
	vector<string>words;
	while (getline(cin, str)) {
		stringstream ss(str);
		while (getline(ss, word, ' '))
			words.push_back(word);
		for (auto it = words.begin(); it != words.end(); it++)
		{
			if (it == words.end() - 1)
				flag = true;
			cont = *it;
			for (int i = 0; i < (cont.length()) / 2; i++)
				swap(cont[i], cont[cont.length() - (i + 1)]);
			if (!flag)
				cout << cont << " ";
			else
				cout << cont;
		}
		cout << endl;
		words.clear();
		flag = false;
	}
	return 0;
}
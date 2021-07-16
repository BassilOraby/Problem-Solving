#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int main() {
	char c;
	string s;
	int n, max = 0, q;
	map<string, int, less<string>>nucleotide;
	map<string, int>::iterator iter;
	nucleotide.insert(std::pair<string, int>("A", 0));
	nucleotide.insert(std::pair<string, int>("C", 0));
	nucleotide.insert(std::pair<string, int>("G", 0));
	nucleotide.insert(std::pair<string, int>("T", 0));
	nucleotide.insert(std::pair<string, int>("?", 0));
	scanf_s("%d\n", &n);
	getline(cin, s);
	if (n%4 != 0) {
		printf("===\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		c = s.at(i);
		std::string conv(1, c);
		iter = nucleotide.find(conv);
		iter->second++;
		if (iter->first != "?" && iter->second > max)
			max = iter->second;
	}
	iter = nucleotide.begin();
	if (iter->second == 0) {
		cout << s << endl;
		return 0;
	}
	q = n / 4;
	if (max <= q)
	{
		for (iter = nucleotide.begin() ; iter != nucleotide.end() ; ++iter)
		{
			if (iter->first == "?")
				continue;
			while (iter->second < q)
			{
				s.replace(s.find('?'), 1, iter->first);
				iter->second++;
			}
		}
	}
	else
	{
		printf("===\n");
		return 0;
	}
	cout << s << endl;
	return 0;
}
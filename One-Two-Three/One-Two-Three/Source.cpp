#include <iostream>
#include <string>
using namespace std;

int main() {
	int trials, count1 = 0, count2 = 0;
	string One = "one", Two = "two", Three = "three", test;
	scanf_s("%d", &trials);
	while (trials--)
	{
		cin >> test;
		if (test.length() == 3) {
			for (size_t i = 0; i < 3; i++)
				if (One[i] == test[i]) count1++;
			for (size_t j = 0; j < 3; j++)
				if (Two[j] == test[j]) count2++;
			count1 > count2 ? printf("1\n") : printf("2\n");
			count1 = 0;
			count2 = 0;
		}
		else
			printf("3\n");
	}
	return 0;
}
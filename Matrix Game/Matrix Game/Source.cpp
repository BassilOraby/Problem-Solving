#include<iostream>
#include<stdio.h>
#include<string>
#define N 100
using namespace std;

int Flip(bool x, int osc) {
	if (x)
		osc = 0;
	else if (osc == 0)
		osc = 1;
	else
		osc = 0;
	return osc;
}

int main() {
	int t, n, m, Arr[N][N] = {}, oscillator = 0;
	bool FirstCall = true, notFound = false;
	string names[2] = { "Ashish", "Vivek" };
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> Arr[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = i; k > 0; k--)
				{
					if (Arr[k - 1][j] == 1 || Arr[i][j] == 0) {
						notFound = false;
						break;
					}
					if (k-1 == 0)
						notFound = true;
				}
			}
			if (notFound)
				oscillator ^= 1;
			notFound = false;
		}
		cout << names[oscillator] << endl;
	}
	system("pause");
	return 0;
}
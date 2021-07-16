#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int A = 0, t, n, d, x[120] = {}, Days, count, ans[120], y;
	scanf_s("%d", &t);
	while (t--)
	{
		cin >> n >> d;
		Days = d;
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &y);
			x[i] = y;
		}
		for (int i = 0; i < n; i++)
		{
			if (i+1 > Days)
				break;
			while ((x[i+1]>0) && ((i+1) <= Days))
			{
				count = i;
				while (count>=0)
				{
					x[count + 1]--;
					x[count]++;
					Days--;
					count--;
				}
			}
		}
		ans[A] = x[0];
		A++;
	}
	for (int i = 0; i < A; i++)
		printf_s("%d\n", ans[i]);
	system("pause");
	return 0;
}
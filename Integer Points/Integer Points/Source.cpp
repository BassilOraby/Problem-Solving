#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

const int pp = 1e5 + 5;
const int qq = 1e5 + 5;

int main() {
	int t, y, x, n, m,count = 0,res=0;
	long arrp[pp], arrq[qq], p, q;
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		while (count != n)
		{
			scanf_s("%l", &p);
			arrp[count] = p;
			++count;
		}
		count = 0;
		scanf_s("%d", &m);
		while (count != m)
		{
			scanf_s("%l", &q);
			arrq[count] = q;
			++count;
		}
		count = 0;
		for (size_t i = 0; i < arrp; i++)
		{

		}
	}
}
#include<iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	int n,q,k,counter = 0,l;
	int* A,*Q;
	string txt;
	cin >> n;
	if (n >= 1 && n <= 1e5)
		A = new int[n];
	else
		return -1;
	for (size_t i = 0; i < n; i++)
	{
		cin >> l;
		while (l<1 || l>100000)
		{
			cin >> l;
		}
		A[i] = l;
	}
	cin >> q;
	if (q >= 1 && q <= 100000)
		Q = new int[q];
	else
		return -1;
	for (size_t i = 0; i < q; i++)
	{
		cin >> k;
		if ( k >= 1 && k<=1e9) 
		Q[i] = k;
	}
	for (size_t i = 0; i < q; i++)
	{
		for (int j = 0; j < n; j++) {
			if (*(A + j) <= *(Q + i)) {
				++counter;
			}
		}
		cout << counter << endl;
		counter = 0;
	}
	system("pause");
	return 0;
}
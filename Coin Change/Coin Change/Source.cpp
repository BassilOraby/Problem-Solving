#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int Cents[5] = { 1,5,10,25,50 }, in, mem[5][7495];

ll CC(int i, int val) {
	if (val == 0)	return 1;
	if (i == 5) return 0;
	if (mem[i][val] != -1) return mem[i][val];
	long long op1 = CC(i + 1, val);
	long long op2 = Cents[i] <= val ? CC(i, val - Cents[i]) : 0;
	return  mem[i][val] = (op1+op2);
}

int main() {
	memset(mem, -1, sizeof mem); 
	while (~scanf_s("%d", &in)) 
		printf("%lld\n", CC(0, in));
	system("pause");
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,arr[100];
	scanf_s("%d", &n);
	for (size_t i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	sort(arr, arr + n);
	for (size_t i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}
#include<iostream>;
using namespace std;

int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return (i + 1);
}

void QuickSort(int A[], int p, int r) {
	if (p < r)
	{
		int q = partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int main() {
	int p = 0, r = 3;
	int arr[] = {20,40,30,10};
	QuickSort(arr, p, r);
	for (int s = 0; s < r+1 ; s++)
	{
		cout << arr[s] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
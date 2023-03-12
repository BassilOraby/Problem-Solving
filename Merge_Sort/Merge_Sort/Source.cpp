#include<iostream>;
#include <limits>;
#include<vector>;
using namespace std;


void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int>L;
	vector<int>R;
	for (int i = 0; i < n1; i++)
		L.push_back(A[p + i]);
	for (int j = 0; j < n2; j++)
		R.push_back(A[q + j + 1]);
	L.push_back(std::numeric_limits<int>::max());
	R.push_back(std::numeric_limits<int>::max());
	int m = 0;
	int n = 0;
	for (int k = p; k <= r; k++) {
		if (L.at(m) <= R.at(n)) {
			A[k] = L.at(m);
			m += 1;
		}
		else {
			A[k] = R.at(n);
			n += 1;
		}
	}
}

void merge_sort(int arrr[], int p, int r) {
	if (p < r)
	{
		int q = floor((p + r) / 2);
		merge_sort(arrr, p, q);
		merge_sort(arrr, q + 1, r);
		merge(arrr, p, q, r);
	}
}

int main() {
	int arr[] = {343,24,66,367};
	int p = 0, r = 3;
	merge_sort(arr, p, r);
	for (size_t i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
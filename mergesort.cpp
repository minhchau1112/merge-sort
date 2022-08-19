#include<iostream>
using namespace std;

void Merge(int* a, int l,int mid, int r, int* b) {
	int i = l, j = mid;
	for (int z = l; z < r; z++) {
		if ((i<mid)&&((j>=r)||a[i] <= a[j])) {
			b[z] = a[i];
			i++;
		}
		else{
			b[z] = a[j];
			j++;
		}
	}
	for (int k = l; k < r; k++) {
		a[k] = b[k];
	}
}

void MergeSort(int* a, int l,int r, int *b) {
	if (r-l<2) return;
	int mid = (l + r) / 2;
	MergeSort(a, l, mid,b);
	MergeSort(a, mid, r,b);
	Merge(a, l,mid, r, b);
}
int main() {
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	MergeSort(a, 0, n,b);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	delete[] a;
	delete[] b;
	return 0;
}
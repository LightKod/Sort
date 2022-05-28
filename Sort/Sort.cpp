// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int* CreateArray(int n, int type) {
		int* a = new int[n];
	switch (type) {
	case 0:
		for (int i = 0; i < n; i++)
		{
			a[i] = rand();
		}
		break;
	case 1:
		//int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = i;
		}
		break;
	case -1:
		//int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = n - i;
		}
		break;
	}
	return a;
}
void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if ((i+1) % 10 == 0) cout << endl;
	}
}
void InsertionSort(int *a, int n) {
	int j, key;

	for (int i = 0; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void RecursiveInsertionSort(int* a, int n) {
	if (n <= 1) return;
	int j, key;

	RecursiveInsertionSort(a, n - 1);

	key = a[n - 1];
	j = n - 2;

	while (j >= 0 && a[j] > key) {
		a[j + 1] = a[j];
		j--;
	}
	a[j + 1] = key;

}
void Merge(int* a, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* temp1 = new int[n1];
	int* temp2 = new int[n2];

	for (int i = 0; i < n1; i++)
	{
		temp1[i] = a[l + i];
	}
	for (int i = 0; i < n2; i++)
	{
		temp2[i] = a[m + i + 1];
	}

	int count1 = 0, count2 = 0;
	int k = l;
	while (count1 < n1 && count2 < n1) {
		if (temp1[count1] > temp2[count2]) {
			a[k++] = temp2[count2++];
		}
		else {
			a[k++] = temp1[count1++];
		}
	}

	while (count1 < n1) {
		a[k++] = temp1[count1++];
	}

	while (count2 < n2) {
		a[k++] = temp2[count2++];
	}
}
void MergeSort(int* a, int l, int r) {
	if (l < r) {
		int m = (l + r - 1) / 2;

		MergeSort(a, l, m);
		MergeSort(a, m+1, r);
		Merge(a, l, m, r);
	}
}
void Heapify(int* a, int n, int root) {
	int largest = root;

	int c1 = root * 2 + 1;
	int c2 = root * 2 + 2;

	if (c1 < n && a[c1] > a[largest]) {
		largest = c1;
	}

	if (c2 < n && a[c2] > a[largest]) {
		largest = c2;
	}

	if (largest != root) Heapify(a, n, largest);
}
void HeapSort(int *a, int n) {
	for (int i = 0; i < n/2-1; i++)
	{
		Heapify(a, n, i);
	}

	for (int i = 0; i < n; i++)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		Heapify(a, i, 0);
	}
}
int GetMax(int* a, int n) {
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i]) max = a[i];
	}
	return max;
}
void CountingSort(int*& a, int n, int digit) {
	int* temp = new int[n];
	int* count = new int[10]{0};

	for (int i = 0; i < n; i++)
	{
		count[(a[i] / digit) % 10]++;
	}
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		temp[count[(a[i] / digit) % 10] - 1] = a[i];
		count[(a[i] / digit) % 10]--;
	}
	
	for (int i = 0; i < n; i++)
		a[i] = temp[i];
}
void RadixSort(int *a, int n) {
	int max = GetMax(a, n);
	//cout << max;
	for (int digit = 1; max / digit > 0; digit *= 10)
		CountingSort(a, n, digit);
}
int Partition(int *a, int start, int end) {
	int pivot = a[(start + end) / 2];
	int i = start;
	int j = end;
	while (i <= j)
	{

		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}

	}
	return i;
}
void QuickSort(int* a, int start, int end) {
	if (start < end)
	{
		int pi = Partition(a, start, end);

		QuickSort(a, start, pi - 1);
		QuickSort(a, pi + 1, end);
	}
}

int main()
{
	int n = 1000000;
	int* a = CreateArray(n,-1);
	//PrintArray(a,n);
	cout<< endl << endl << endl;
	clock_t t = clock();
	//InsertionSort(a, n);
	HeapSort(a, n);
	//MergeSort(a, 0,n - 1);
	//QuickSort(a, 0,n - 1);
	//RadixSort(a, n);
	//RecursiveInsertionSort(a, n);
	t = clock() - t;
	//PrintArray(a,n);
	cout<< endl << t << "ms";
	
}
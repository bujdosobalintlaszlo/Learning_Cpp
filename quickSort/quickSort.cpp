// quickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void csere(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int randomInd(int p, int r) {
	return p + std::rand() % (r - p + 1);
}

int partition(int* a, int p, int r) {
	int i = randomInd(p,r);
	csere(&a[i], &a[r]);
	i = p;
	while (i < r && a[i] <= a[r]) {
		++i;
	}
	if (i < r) {
		int j = i + 1;
		while (j < r) {
			if (a[j] < a[r]) {
				csere(&a[i], &a[j]);
				++i;
			}
			else {
				//SKIP
			}
			++j;
		}
		csere(&a[i], &a[r]);
	}
	else {
		//SKIP
	}
	return i;
}

void QuickSort(int *a,int p,int r) {
	if (p < r) {
		int q = partition(a,p,r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
void quickSort(int *a,int n) {
	QuickSort(a,0, n - 1);
}

int main()
{
	int arr[7] = { 12,31,23,20,14,55,11 };
	quickSort(arr, 7);
	for (int i = 0; i < 7; ++i) {
		std::cout << arr[i] << " ";
	}
}


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void Merge(int a[], int l, int r) {
	int m = (l + r) / 2;
	int n1 = m - l + 1;
	int n2 = r - m;
	int a1[n1 + 1];
	int a2[n2 + 1];
	for (int i = 0; i < n1; i++) a1[i] = a[l + i];
	for (int i = 0; i < n2; i++) a2[i] = a[m + 1 + i];
	a1[n1] = a2[n2] = INF;
	int p1, p2;
	p1 = p2 = 0;
	for (int i = l; i <= r; i++) {
		if (a1[p1] < a2[p2]) {
			a[i] = a1[p1];
			p1++;
		} else {
			a[i] = a2[p2];
			p2++;
		}
	}
}

void MergeSort(int a[], int l, int r) {
	// Ocurre cuando el intervalo longitud mayor que 1
	if (l < r) {
		int m = (l + r) / 2;
		MergeSort(a, l, m); // Ordeno la mitad izquierda
		MergeSort(a, m + 1, r); // Ordeno la mitad derecha
		Merge(a, l, r); // Fusiono las mitades
	}
}

int main() {
	int a[] = {5, 6, -1, 69, 24, 8, -10, 9};
	int n = sizeof(a) / sizeof(int);
	cout << "a[]: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	MergeSort(a, 0, n - 1);
	cout << "Luego de ordenarlo:" << endl;
	cout << "a[]: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}

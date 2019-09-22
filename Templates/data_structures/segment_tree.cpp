#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int tree[4 * N];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		tree[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(a, 2 * v, tl, tm);
		build(a, 2 * v + 1, tm + 1, tr);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
}

int sum(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (l == tl and r == tr) return tree[v];
	int tm = (tl + tr) / 2;
	return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		tree[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm) update(2 * v, tl, tm, pos, new_val);
		else update(2 * v + 1, tm + 1, tr, pos, new_val);
		tree[v] = tree[2 * v] + tree[2 * v + 1];
	}
}

int main() {
	int a[] = {2, 3, 10, -1, 8, 3, 2, 100};
	int n = sizeof(a) / sizeof(int);
	// Creo el segment tree sobre el arreglo a[]
	build(a, 1, 0, n - 1);
	// Hare consultas 
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			printf("La suma de los elementos desde la posicion %d hasta la posicion %d es %d.\n", i, j, sum(1, 0, n - 1, i, j));
	// Hare ciertas modificaciones a algunos elementos
	update(1, 0, n - 1, 3, 50);
	update(1, 0, n - 1, 0, -69);
	update(1, 0, n - 1, 6, 42);
	// De nuevo consultare
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			printf("La suma de los elementos desde la posicion %d hasta la posicion %d es %d.\n", i, j, sum(1, 0, n - 1, i, j));
	return 0;
}

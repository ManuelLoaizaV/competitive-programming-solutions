#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int LG = 17;
const int INF = 1e9;

int st[N][LG + 1];

void build(int a[], int n) {
	for (int i = 0; i < n; i++) st[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// O(lgn)
int query_1(int l, int r) {
	int ans = INF;
	int t = r - l + 1;
	int lg = 32 - (__builtin_clz(t) + 1);
	for (int i = lg; i >= 0; i--) {
		if ((1 << i) <= t) {
			ans = min(ans, st[l][i]);
			l += (1 << i);
			t -= (1 << i);
		}
	}
	return ans;
}

// O(1)
int query_2(int l, int r) {
	int t = r - l + 1;
	int lg = 32 - (__builtin_clz(t) + 1);
	return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
}

int main() {
	int a[] = {2, 3, 10, -1, 8, 3, 2, 100};
	int n = sizeof(a) / sizeof(int);
	build(a, n);
	cout << "a[] : ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		int l = rand() % n;
		int r = rand() % n;
		if (r < l) swap(l, r);
		printf("min(a_i), %d <= i <= %d\n", l, r);
		printf("query 1: %d\n", query_1(l, r));
		printf("query 2: %d\n", query_2(l, r));
	}
	return 0;
}

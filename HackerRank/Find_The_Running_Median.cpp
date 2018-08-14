//
// Created by ManuelLoaiza on 05/20/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
int tree[MAX_N + 2];

struct FenwickTree {
	void update(int i, int delta) {
		while (i <= MAX_N + 1) {
			tree[i] += delta;
			i += (i & - i);
		}
	}
	
	int query(int i) {
		int sum = 0;
		while (i > 0) {
			sum += tree[i];
			i -= (i & - i);
		}
		return sum;
	}
}ft;

bool predicate(int middle, int x) {
	return ft.query(middle + 1) >= x;
}

int binarySearch(int left, int right, int x) {
	while (right - left > 1){
		int middle = (left + right) / 2;
		if (predicate(middle, x)) right = middle;
		else left = middle;
	}
	return right;
}

int main() {
	int n, a, half;
	double answer;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ft.update(a + 1, 1);
		half = i / 2;
		if (i % 2 == 0) {
			answer = (1.0 * binarySearch(0, MAX_N, half) + binarySearch(0, MAX_N, half + 1)) / 2;
		} else {
			answer = 1.0 * binarySearch(0, MAX_N, half + 1);
		}
		cout << fixed << setprecision(1) << answer << endl;
	}
	return 0;
}

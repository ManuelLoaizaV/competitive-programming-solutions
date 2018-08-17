//
// Created by ManuelLoaiza on 06/03/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_LG = 18;
const int MAX_N = 1e+5;
int a[MAX_N];
int ST[MAX_N][MAX_LG];

void initialize(int n) {
	for (int i = 0; i < n; i++) ST[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			ST[i][j] = __gcd(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int answer = a[l];
	int T = r - l + 1;
	int lg = 31 - __builtin_clz(T);
	for (int j = lg; j >= 0; j--) {
		if ((1 << j) <= T) {
			answer = __gcd(answer, ST[l][j]);
			l += (1 << j);
			T -= (1 << j);
		}
	}
	return answer;
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	initialize(n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		int answer;
		if (l == 1) {
			answer = query(r, n - 1);
		} else {
			if (r == n) {
				answer = query(0, l - 2);
			} else {
				answer = __gcd(query(0, l - 2), query(r, n - 1));
			}
		}
		cout << answer << endl;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int testCases;
	cin >> testCases;
	while (testCases--) solve();
	return 0;
}


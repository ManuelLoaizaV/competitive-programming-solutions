//
// Created by ManuelLoaiza on 11/11/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
	ll n;
	cin >> n;
	ll a[n][n];
	ll row[n], col[n];
	for (int i = 0; i < n; i++) {
		row[i] = 0;
		col[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	ll answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (col[j] > row[i]) answer++;
		}
	}
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}


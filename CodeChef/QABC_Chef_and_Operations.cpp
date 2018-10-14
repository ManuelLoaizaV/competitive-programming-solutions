//
// Created by ManuelLoaiza on 10/13/18
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e+5;

ll a[MAX_N + 5], b[MAX_N + 5];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n - 2; i++) {
		ll delta = b[i] - a[i];
		if (delta == 0) continue;
		if (delta > 0) {
			a[i] += delta;
			a[i + 1] += 2 * delta;
			a[i + 2] += 3 * delta;
		} else {
			cout << "NIE" << endl;
			return; 
		}
	}
	for (int i = max(0, n - 3); i < n; i++) {
		if (a[i] != b[i]) {
			cout << "NIE" << endl;
			return;
		}
	}
	cout << "TAK" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
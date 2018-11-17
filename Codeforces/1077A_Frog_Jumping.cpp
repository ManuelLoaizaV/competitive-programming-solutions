//
// Created by ManuelLoaiza on 11/16/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;

void solve() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, k;
		cin >> a >> b >> k;
		ll answer = 0;
		ll m = k / 2;
		if (k % 2 == 0) {
			answer = a * m - b * m;
		} else {
			answer = a * (m + 1) - b * m;
		}
		cout << answer << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}


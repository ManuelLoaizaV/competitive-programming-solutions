//
// Created by ManuelLoaiza on 11/16/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int answer = 0;
	for (int i = 1; i < n - 1; i++) {
		if (a[i - 1] == 1 and a[i] == 0 and a[i + 1] == 1) {
			a[i + 1] = 0;
			answer++;
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


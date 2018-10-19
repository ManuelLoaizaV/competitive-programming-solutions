//
// Created by ManuelLoaiza on 10/13/18
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;

int S[MAX_N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> S[i];
	sort(S, S + n);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] >= S[n - k]) answer++;
	}
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
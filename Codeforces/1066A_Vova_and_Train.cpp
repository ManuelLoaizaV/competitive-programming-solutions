//
// Created by ManuelLoaiza on 10/12/18
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;

void solve() {
	ll L, v, l, r;
	cin >> L >> v >> l >> r;
	ll answer = L / v;
	ll a1 = r / v;
	ll a2 = (l - 1) / v;
	answer = answer - a1 + a2;
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}


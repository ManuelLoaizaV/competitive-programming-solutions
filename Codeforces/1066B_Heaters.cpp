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

const int MAX_N = 1e+4;
bool a[MAX_N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int answer = 0;
	int i = 1;
	while (i <= n) {
		bool possible = false;
		for (int j = i + r - 1; j >= i - r + 1; j--) {
			if (j < 1) break;
			if (a[j]) {
				answer++;
				a[j] = false;
				possible = true;
				i = j + r - 1;
				break;
			}
		}
		if (not possible) {
			cout << "-1" << endl;
			return 0;
		}
		i++;
	}
	cout << answer << endl;
	return 0;
}


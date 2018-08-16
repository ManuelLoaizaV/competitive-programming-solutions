//
// Created by ManuelLoaiza on 06/03/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;

struct Stone {
	long long a;
	long long b;
} s[MAX_N];

void solve() {
	long long n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i].a;
	for (int i = 0; i < n; i++) cin >> s[i].b;
	
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		long long t = k / s[i].a;
		answer = max(answer, t * s[i].b);
	}	
	cout << answer << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	int testCases;
	cin >> testCases;
	while (testCases--) solve();
	return 0;
}


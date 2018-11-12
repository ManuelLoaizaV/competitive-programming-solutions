//
// Created by ManuelLoaiza on 11/11/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2000;

void solve() {
	string s, u;
	cin >> s >> u;
	int n = s.size();
	int m = u.size();
	string mierda = "";
	for (int i = 0; i < MAX_N; i++) mierda += '#';
	s = mierda + s + mierda;
	int answer = m;
	for (int i = 0; i <= MAX_N + n; i++) {
		int temp = 0;
		for (int j = 0; j < m; j++) {
			if (s[i + j] != u[j]) temp++;
		}
		answer = min(answer, temp);
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

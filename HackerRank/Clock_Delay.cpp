//
// Created by ManuelLoaiza on 06/03/18
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	h1 += k;
	int answer = 0;
	if (h1 == h2) {
		answer = m1 - m2;
	} else {
		answer = 60 - m2;
		h2++;
		m2 = 0;
		answer += (h1 - h2) * 60 + m1;
	}
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}


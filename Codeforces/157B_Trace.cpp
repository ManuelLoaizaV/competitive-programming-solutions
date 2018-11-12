//
// Created by ManuelLoaiza on 11/11/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;
const ld PI = acos(-1);

void solve() {
	int n;
	cin >> n;
	int r[n];
	for (int i = 0; i < n; i++) cin >> r[i];
	sort(r, r + n);
	ld answer = 0;
	ll R2 = 0;
	if (n % 2 == 0) {
		for (int i = 1; i < n; i += 2) R2 += (r[i] * r[i] - r[i - 1] * r[i - 1]);	
	} else {
		R2 = r[0] * r[0];
		for (int i = 2; i < n; i += 2) R2 += (r[i] * r[i] - r[i - 1] * r[i - 1]);	
	}
	answer = PI * R2;
	cout << fixed << setprecision(10) << answer << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int odd, even;
	odd = even = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) even++;
		else odd++;
	}
	if (odd == 0) {
		cout << "NO" << endl;
		return;
	}
	if (even == 0) {
		if (odd % 2 == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

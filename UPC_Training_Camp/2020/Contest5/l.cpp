#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> k;
		ans |= k;
	}
	cout << ans << endl;
}

int main() {
	freopen("looking.in", "r", stdin);
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
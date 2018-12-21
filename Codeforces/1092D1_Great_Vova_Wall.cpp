#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	stack<int> acc;
	for (int i = 0; i < n; i++) {
		int mod = a[i] % 2;
		if (acc.empty()) {
			acc.push(mod);
		} else {
			if (acc.top() == mod) acc.pop();
			else acc.push(mod);
		}
	}
	if (acc.size() < 2) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
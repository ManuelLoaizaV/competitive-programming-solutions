#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cout << char('a' + i % k);
	cout << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
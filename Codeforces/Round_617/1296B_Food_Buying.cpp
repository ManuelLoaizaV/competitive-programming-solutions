#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void solve() {
	long long ans = 0LL;
	long long s;
	cin >> s;
	while (s >= 10) {
		long long maxi = s / 10 * 10;
		ans += maxi;
		s = s - maxi + maxi / 10;
	}
	ans += s;
	cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

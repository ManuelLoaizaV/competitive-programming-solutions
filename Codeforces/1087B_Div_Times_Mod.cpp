#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 9223372036854775807LL;

void solve() {
	ll n, k;
	cin >> n >> k;
	ll answer = INF;
	for (int r = 1; r < k; r++) {
		ll x = k * n / r + r;
		ll q = x / k;
		if ((k * n) % r == 0 and q * r == n)
			answer = min(answer, x);
	}
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
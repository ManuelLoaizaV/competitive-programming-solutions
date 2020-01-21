#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

const long double PI = acos(-1);

void solve() {
	int n;
	cin >> n;
	long double r = cos(PI / n) * cos(PI / n);
	long double ans = 10000.0 / (1.0 - r);
	cout << fixed << setprecision(5) << ans << endl;
}

int main() {
	freopen("baklava.in", "r", stdin);
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 1e+5;
const ll INF = 	9223372036854775807;

void solve() {
	ll n;
	cin >> n;
	ll b[n + 1], a[n + 1];
	for (int i = 1; 2 * i <= n; i++)
		cin >> b[i];
	for (int i = 1; 2 * i <= n; i++) {
		if (i == 1) {
			a[i] = 0;
			a[n - i + 1] = b[i];
		} else {
			if (b[i] - a[i - 1] <= a[n - i + 2]) {
				a[i] = a[i - 1];
				a[n - i + 1] = b[i] - a[i];
			} else {
				a[n - i + 1] = a[n - i + 2];
				a[i] = b[i] - a[n - i + 1];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
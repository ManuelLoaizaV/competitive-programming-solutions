#include <bits/stdc++.h>
#define debug cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+6;
const int ALPH = 26;

ll mini(ll a, ll b) {
	if (a < b) return a;
	return b;
}

void solve() {
	ll n, s, sum = 0;
	cin >> n >> s;
	ll v[n];
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) sum += v[i];
	//ll minimo = v[0];
	//for (int i = 1; i < n; i++) minimo = mini(mini, v[i]);
	sort(v, v + n);
	if (s > sum) {
		cout << -1 << endl;
		return;
	}
	ll ward = 0;
	for (int i = 0; i < n; i++) ward += v[i] - v[0];
	if (s <= ward) {
		cout << v[0] << endl;
		return;
	}
	s -= ward;
	for (int i = 0; i < n; i++) v[i] = v[0];
	ll xd = ceil(1.0 * s / n);
	cout << v[0] - xd << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
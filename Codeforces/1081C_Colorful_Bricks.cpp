#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
//std::map<>::iterator it;
const int MAX_N = 2000;
const int ALPH = 26;
const ll INF = 9223372036854775807;
const ll mod = 998244353;
const ld PI = acos(-1);
ll C[MAX_N + 1][MAX_N + 1];

ll fastPow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precalculate() {
	C[0][0] = 1LL;
	for (int n = 1; n <= MAX_N; n++) {
    	C[n][0] = C[n][n] = 1LL;
    	for (int k = 1; k < n; k++)
        	C[n][k] = (C[n - 1][k - 1] % mod + C[n - 1][k] % mod) % mod;
    }
}

void solve() {
	precalculate();
	ll n, m, k, answer;
	cin >> n >> m >> k;
	if (k == 0) {
		answer = m;
	} else {
		if (n == 1) {
			answer = 0;
		} else {
			answer = (((m * fastPow(m - 1, k)) % mod) * (C[n - 1][k] % mod)) % mod;
		}
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
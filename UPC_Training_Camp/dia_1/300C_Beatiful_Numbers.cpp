#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;
const ll N = 1e6;
ll fact[N + 1];

bool ok(ll sum, ll a, ll b) {
	while (sum > 0LL) {
		ll digit = sum % 10LL;
		if (digit != a and digit != b) return false;
		sum /= 10LL;
	}
	return true;
}

ll binPow(ll a, ll b) {
	if (b == 0) return 1LL;
	ll p = binPow(a, b / 2);
	if (b % 2 == 0) return ((p * p) % MOD);
	return ((((p * p) % MOD) * a) % MOD);
}

ll modInv(ll a, ll b) {
	return binPow(a, MOD - 2LL);
}

ll comb(ll n, ll k) {
	return ((fact[n] * modInv((fact[k] * fact[n - k]) % MOD, MOD)) % MOD);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fact[0] = 1LL;
	for (ll i = 1LL; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
	ll a, b, n;
	cin >> a >> b >> n;
	ll ans = 0LL;
	// k digits a and (n - k) digits b
	for (ll k = 0; k <= n; k++) {
		ll sum = k * a + (n - k) * b;
		if (ok(sum, a, b)) ans = (ans + comb(n, k)) % MOD;
	}
	cout << ans << endl;
	return 0;
}

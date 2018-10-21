#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long int ll;

const ll MAX = 998244353;

ll row[2010];
ll col[2010];

ll maxi(ll a, ll b) {
	if (a > b) return a;
	else return b;
}

int main() {
	fastio;
	ll n, m, k, ac = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		ac += k;
		row[i] = ac;
	}
	ac = 0;
	for (ll i = 0; i < m; i++) {
		cin >> k;
		ac += k;
		col[i] = ac;
	}
	ll a = row[0], b = col[0];
	ll z = row[0], w = col[0];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < i; j++) {
			a = max(a, row[i] - row[j]);
			z = min(z, row[i] - row[j]);
		}
		a = max(a, row[i]);
		z = min(z, row[i]);
	}
	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < i; j++) {
			b = max(b, col[i] - col[j]);
			w = min(w, col[i] - col[j]);
		}
		b = max(b, col[i]);
		w = min(w, col[i]);
	}
	ll res = maxi(a * w, maxi(z * b, maxi(a * b, z * w)));
	cout << res;
	return 0;

}
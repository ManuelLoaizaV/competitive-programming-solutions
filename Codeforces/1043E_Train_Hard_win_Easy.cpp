#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 9223372036854775807;

struct Men {
	ll id, x, y, delta;
	bool operator < (Men &otroMen) const {
		if (delta == otroMen.delta) return id < otroMen.id;
		return delta < otroMen.delta;
	}
};

ll mini(ll a, ll b) {
	if (a < b) return a;
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	Men mens[n];
	for (ll i = 0; i < n; i++) {
		cin >> mens[i].x >> mens[i].y;
		mens[i].id = i;
		mens[i].delta = mens[i].x - mens[i].y;
	}
	vector<ll> rivals[n];
	while (m--) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		rivals[u].push_back(v);
		rivals[v].push_back(u);
	}

	Men ward[n];
	for (ll i = 0; i < n; i++) ward[i] = mens[i];
	sort(ward, ward + n);
	ll accX[n], accY[n];
	for (ll i = 0; i < n; i++) {
		if (i == 0) {
			accX[i] = ward[i].x;
			accY[i] = ward[i].y;
		} else {
			accX[i] = ward[i].x + accX[i - 1];
			accY[i] = ward[i].y + accY[i - 1];
		}
	}

	ll answer[n];
	for (ll i = 0; i < n; i++) {
		ll u = ward[i].id;
		answer[u] = INF;
		if (i == 0) {
			answer[u] = mens[u].x * (n - 1) + accY[n - 1] - accY[i];
		} else {
			if (i == n - 1) {
				answer[u] = mens[u].y * i + accX[i - 1];
			} else {
				answer[u] = mens[u].y * i + accX[i - 1] + mens[u].x * (n - 1 - i) + (accY[n - 1] - accY[i]);
			}
		}
		ll l = rivals[u].size();
		for (ll j = 0; j < l; j++) {
			ll v = rivals[u][j];
			ll substact = mini(mens[u].x + mens[v].y, mens[u].y + mens[v].x);
			answer[u] -= substact;
		}
	}
	for (ll i = 0; i < n; i++) {
		if (answer[i] == INF) cout << "0";
		else cout << answer[i];
		cout << " ";
	}
	return 0;
}
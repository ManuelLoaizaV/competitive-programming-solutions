//
// Created by ManuelLoaiza on 11/16/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;

map<ll, ll> ward;
std::map<ll, ll>::iterator it;

void solve() {
	ll n;
	cin >> n;
	ll a[n + 1];
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		it = ward.find(a[i]);
		if (it != ward.end()) ward[a[i]]++;
		else ward[a[i]] = 1LL;
		sum += a[i];
	}
	vector<ll> answer;
	for (ll i = 1; i <= n; i++) {
		ll xd = sum - a[i];
		if (xd % 2 == 0) {
			it = ward.find(xd / 2);
			if (it != ward.end()) {
				if (xd / 2 == a[i]) {
					if ((it->second) > 1) answer.push_back(i);
				} else {
					answer.push_back(i);
				}
			}
		}
	}
	ll l = answer.size();
	cout << l << endl;
	for (ll i = 0; i < l; i++) cout << answer[i] << " ";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}


#include <bits/stdc++.h>
#define debug cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+6;
const int ALPH = 26;
const ll mod = 1000000007;

void solve() {
	string s;
	cin >> s;
	ll l = s.size();
	vector<ll> acc;
	ll ward = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] == 'a') {
			ward++;
		} else {
			if (s[i] == 'b') {
				acc.pb(ward);
				ward = 0;
			}
		}
	}
	if (ward > 0) acc.pb(ward);
	ll answer = 0;
	ll xd = acc.size();
	if (xd > 0) {
	    answer = (acc[0] + 1);
		for (int i = 1; i < xd; i++)
			answer = (answer * (acc[i] + 1)) % mod;
		answer--;
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
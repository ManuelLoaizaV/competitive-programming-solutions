#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 1e+5;
const ll INF = 	9223372036854775807;

void solve() {
	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		ll answer = 0;
		if (x % 2 == 0) {
			answer = x / 2;
		} else {
			answer++;
			x -= 3;
			answer += x / 2;
		}
		cout << answer << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
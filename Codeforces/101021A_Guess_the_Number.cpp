#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
//std::map<>::iterator it;
const int MAX_N = 1e+5;
const int ALPH = 26;
const int INF = 9223372036854775807;
const ld PI = acos(-1);

void solve() {
	int l = 1;
	int r = 1000000;
	string sign;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		cout << mid << endl << flush;
		cin >> sign;
		if (sign == "<") r = mid - 1;
		else l = mid;
	}
	cout << r << endl << flush;
	cin >> sign;
	if (sign == "<") cout << "! " << l << endl << flush;
	else cout << "! " << r << endl << flush;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
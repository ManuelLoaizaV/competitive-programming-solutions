#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 1e+6;
const ll INF = 9223372036854775807LL;
const int ALPH = 26;
//std::map<int, int>::iterator it;
string alph = "abcdefghijklmnopqrstuvwxyz";
string digit = "0123456789";

void solve() {
	string s;
	cin >> s;
	int l = s.size();
	string answer = "";
	int pos = 0;
	if (l % 2 == 0) pos = l / 2 - 1;
	else pos = l / 2;
	for (int i = 0; i < l; i++) {
		if (i % 2 == 0) pos -= i;
		else pos += i;
		answer += s[pos];
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
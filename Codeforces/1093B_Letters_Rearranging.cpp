#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 1e+5;
const ll INF = 	9223372036854775807;
string xd = "abcdefghijklmnopqrstuvwxyz";

void solve() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		char c = s[0];
		int l = s.size();
		bool print = false;
		for (int i = 0; i < l; i++) {
			if (s[i] != c) {
				print = true;
				break;
			}
		}
		if (print) {
			int alph = 26;
			int f[alph];
			memset(f, 0, sizeof(f));
			for (int i = 0; i < l; i++)
				f[s[i] - 'a']++;
			string answer = "";
			for (int i = 0; i < alph; i++)
				for (int j = 0; j < f[i]; j++)
					answer = answer + xd[i];
			cout << answer << endl;
		}
		else cout << -1 << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
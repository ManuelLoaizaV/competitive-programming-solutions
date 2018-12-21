#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

bool possible = true;
string answer;

void check(string prefix, string suffix, string s[], int n) {
	bool used[n];
	answer = "";
	for (int i = 0; i < n; i++) {
		used[i] = false;
		answer += '#';
	}
	int l = prefix.size();
	for (int i = l; i > 0; i--) {
		string aux = prefix.substr(0, i);
		bool found = false;
		for (int j = 0; j < n; j++) {
			if (s[j] == aux and not used[j]) {
				found = true;
				used[j] = true;
				answer[j] = 'P';
				break;
			}
		}
		if (not found) {
				possible = false;
				return;
		}
	}
	for (int i = l; i > 0; i--) {
		string aux = suffix.substr(l - i, i);
		bool found = false;
		for (int j = 0; j < n; j++) {
			if (s[j] == aux and not used[j]) {
				found = true;
				used[j] = true;
				answer[j] = 'S';
				break;
			}
		}
		if (not found) {
			possible = false;
			return;
		}
	}
}

void solve() {
	int n;
	cin >> n;
	int l = 2 * n - 2;
	string s[l];
	for (int i = 0; i < l; i++) cin >> s[i];
	string max1, max2;
	max1 = max2 = "";
	for (int i = 0; i < l; i++) {
		if (s[i].size() == n - 1) {
			if (max1 == "") {
				max1 = s[i];
			}
			else {
				max2 = s[i];
				break;
			}
		}
	}
	check(max1, max2, s, l);
	if (not possible) check(max2, max1, s, l);
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
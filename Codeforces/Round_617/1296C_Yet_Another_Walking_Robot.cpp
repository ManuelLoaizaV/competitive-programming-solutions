#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	pair<int, int> acc;
	acc = {0, 0};
	map<pair<int, int>, int> h;
	h[acc] = 0;
	vector<vector<int>> pos;
	pos.push_back(vector<int>());
	pos[0].push_back(0);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') acc.first--;
		if (s[i] == 'R') acc.first++;
		if (s[i] == 'U') acc.second++;
		if (s[i] == 'D') acc.second--;
		if (h.count(acc) == 0) {
			int sz = pos.size();
			h[acc] = sz;
			pos.push_back(vector<int>());
			pos[sz].push_back(i + 1);
		} else {
			int ind = h[acc];
			pos[ind].push_back(i + 1);
		}
	}
	int maxi = 1e9;
	pair<int, int> ans;
	int len = pos.size();
	for (int i = 0; i < len; i++) {
		int sz = pos[i].size();
		for (int j = 0; j < sz - 1; j++) {
			int temp = pos[i][j + 1] - pos[i][j];
			if (temp < maxi) {
				maxi = temp;
				ans.first = pos[i][j] + 1;
				ans.second = pos[i][j + 1];
			}
		}
	}
	if (maxi == 1e9) {
		cout << -1 << endl;
	} else {
		cout << ans.first << " " << ans.second << endl;
	}
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

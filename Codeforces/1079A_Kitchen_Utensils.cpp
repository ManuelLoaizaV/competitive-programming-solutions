#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 100;

void solve() {
	int n, k;
	cin >> n >> k;
	map<int, int> remain;
	std::map<int, int>::iterator it;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		remain[x]++;
	}
	vector<int> ward;
	for (it = remain.begin(); it != remain.end(); it++) ward.push_back(it->second);
	int l = ward.size();
	int maxi;
	for (int i = 0; i < l; i++) {
		if (i == 0) maxi = ward[i];
		else maxi = max(maxi, ward[i]);
	}
	int xd = maxi / k;
	if (xd * k != maxi) maxi = k * (xd + 1);
	int answer = 0;
	for (int i = 0; i < l; i++) {
		answer += (maxi - ward[i]);
	}	
	cout << answer << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}


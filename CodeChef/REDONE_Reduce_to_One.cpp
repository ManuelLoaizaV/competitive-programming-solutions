#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long Long;
const int MAX_N = 1e6;
const Long mod = 1000000007LL;
Long dp[MAX_N + 2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1LL;
	for (Long i = 2LL; i <= MAX_N; i++) {
		dp[i] = (dp[i - 1] + i + (dp[i - 1] * i) % mod) % mod;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}

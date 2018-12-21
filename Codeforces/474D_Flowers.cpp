#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1e+5;
const int mod = 1000000007;

ll dp[MAX_N + 1];
ll sum[MAX_N + 1];

ll f(int n, int k) {
	if (n < 0) return 0;
	if (n == 0) return 1;	
	if (dp[n] != -1) return dp[n];
	dp[n] = (f(n - k, k) + f(n - 1, k)) % mod;
	return dp[n];
}

int main() {
	int t, k;
	cin >> t >> k;
	for (int i = 0; i <= MAX_N; i++) dp[i] = -1;
	f(MAX_N, k);
	dp[0] = 0;
	for (int i = 1; i <= MAX_N; i++) {
		sum[i] = dp[i] + sum[i - 1];
	}
	while (t--) {
		int a, b;
		cin >> a >> b;
		ll answer = (sum[b] - sum[a - 1]) % mod;
		cout << answer << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Long n, W;
	cin >> n >> W;
	Long w[n], v[n];
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	Long dp[W + 1];
	memset(dp, 0LL, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = W - w[i]; j >= 0; j--) {
			dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
		}
	}
	Long answer = 0LL;
	for (int i = 0; i <= W; i++) answer = max(answer, dp[i]);
	cout << answer << endl;
	return 0;
}
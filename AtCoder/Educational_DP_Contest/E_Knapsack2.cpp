#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const Long INF = 1000000000000000000LL;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Long n, W;
	cin >> n >> W;
	Long w[n], v[n];
	Long sum = 0LL;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		sum += v[i];
	}
	Long dp[sum + 1];
	for (int i = 0; i <= sum; i++) dp[i] = INF;
	dp[0] = 0LL;
	for (int i = 0; i < n; i++) {
		for (int j = sum - v[i]; j >= 0; j--) {
			dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
		}
	}
	Long answer = 0LL;
	for (Long i = 0; i <= sum; i++) {
		if (dp[i] > 0 and dp[i] <= W) {
			answer = max(answer, i);
		}
	}
	cout << answer << endl;
	return 0;
}
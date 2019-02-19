#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	int dp[n];
	for (int i = 0; i < n; i++) dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 2; j++) {
			int k = i + j;
			if (k == n) break;
			dp[k] = min(dp[k], dp[i] + abs(h[k] - h[i]));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
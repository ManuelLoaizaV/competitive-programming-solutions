#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, K;
	cin >> n >> K;
	int h[n], dp[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 1; k <= K; k++) {
			int j = i + k;
			if (j == n) break;
			dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long Long;
const int MAX_N = 50;
const Long INF = 1e9;
Long cuts[MAX_N + 2];
Long dp[MAX_N + 2][MAX_N + 2];

Long mini(Long a, Long b) {
	if (a < b) return a;
	return b;
}

Long DP(int left, int right) {
	if (left + 1 == right) return 0;
	if (dp[left][right] != -1) return dp[left][right];
	dp[left][right] = INF;
	for (int cut = left + 1; cut < right; cut++) {
		dp[left][right] = mini(dp[left][right], DP(left, cut) + DP(cut, right));
	}
	dp[left][right] += (cuts[right] - cuts[left]);
	return dp[left][right];
}

void solve(int l) {
	int n;
	cin >> n;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			dp[i][j] = -1; 
		}
	}
	cuts[0] = 0;
	for (int i = 1; i <= n; i++) cin >> cuts[i];
	cuts[n + 1] = l;
	Long answer = DP(0, n + 1);
	cout << "The minimum cutting is " << answer << "." << endl;
}

int main() {
	fastio;
	int l;
	while (cin >> l) {
		if (l == 0) break;
		solve(l);
	}
	return 0;
}
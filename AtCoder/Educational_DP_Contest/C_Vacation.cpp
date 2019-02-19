#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int p[n][3], dp[n][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> p[i][j];
			dp[i][j] = 0;
		}
	}
	for (int j = 0; j < 3; j++) dp[0][j] = p[0][j];
	for (int day = 1; day < n; day++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j) {
					dp[day][i] = max(dp[day][i], dp[day - 1][j] + p[day][i]);
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 3; i++) answer = max(answer, dp[n - 1][i]);
	cout << answer << endl;
	return 0;
}
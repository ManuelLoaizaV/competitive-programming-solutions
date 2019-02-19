#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int sz_a = a.size();
	int sz_b = b.size();
	int dp[sz_a + 1][sz_b + 1];
	for (int i = 0; i <= sz_a; i++) dp[i][0] = 0;
	for (int i = 0; i <= sz_b; i++) dp[0][i] = 0;
	for (int i = 1; i <= sz_a; i++) {
		for (int j = 1; j <= sz_b; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	string answer = "";
	int i = sz_a;
	int j = sz_b;
	while (dp[i][j] != 0) {
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
		} else {
			if (dp[i][j] == dp[i - 1][j]) {
				i--;
			} else {
				answer += a[i - 1];
				i--;
				j--;
			}
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer << endl;
	return 0;
}
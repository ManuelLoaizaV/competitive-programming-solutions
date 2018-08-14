//
// Created by ManuelLoaiza on 03/04/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 2e+3;
int dp[MAX_SIZE][MAX_SIZE];
string A, B;

int LCS(int n, int m) {
	if (n < 0) return m + 1;
	if (m < 0) return n + 1;
	if (dp[n][m] != -1) return dp[n][m];
	if (A[n] == B[m]) dp[n][m] = LCS(n - 1, m - 1);
	else {
		dp[n][m] = min(1 + LCS(n - 1, m - 1), min(1 + LCS(n - 1, m), 1 + LCS(n, m - 1)));
	}
	return dp[n][m];
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> A >> B;
	int answer = LCS(A.size() - 1, B.size() - 1);
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

/* 
//ITERATIVE SOLUTION

#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 2e+3;
int dp[MAX_SIZE + 1][MAX_SIZE + 1];
string A, B;

void solve() {
	cin >> A >> B;
	int n = A.size();
	int m = B.size();
	for (int i = 0; i <= n; i++) dp[0][i] = i;
	for (int i = 0; i <= m; i++) dp[i][0] = i;
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(1 + dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
		}
	}
	printf("%d\n", dp[n][m]);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
*/

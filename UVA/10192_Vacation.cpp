//
// Created by manuelloaiza on 03/04/18
// Updated on 03/11/18
//
#include <bits/stdc++.h>

using namespace std;

// ITERATIVE SOLUTION

const int MAX_SIZE = 100;
int dp[2][MAX_SIZE + 1];
string travelSequence1, travelSequence2;

int main() {
	int testCase = 1;
	while (true) {
		getline(cin, travelSequence1);
		if (travelSequence1[0] == '#') break;
		getline(cin, travelSequence2);
		int n = travelSequence1.size();
		int m = travelSequence2.size();
		for (int i = 0; i <= n; i++) dp[i & 1][0] = 0;
		for (int i = 0; i <= m; i++) dp[0 & 1][i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (travelSequence1[i - 1] == travelSequence2[j - 1]) dp[i & 1][j] = 1 + dp[(i - 1) & 1][j - 1];
				else dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", testCase, dp[n & 1][m]);
		testCase++;
	}
	return 0;
}

// RECURSIVE SOLUTION
/*
const int MAX_SIZE = 100;
int dp[MAX_SIZE][MAX_SIZE];
string travelSequence1, travelSequence2;

int LCS(int n, int m) {
	if (n < 0 or m < 0) return 0;
	if (dp[n][m] != -1) return dp[n][m];
	if (travelSequence1[n] == travelSequence2[m]) {
		dp[n][m] = 1 + LCS(n - 1, m - 1);
	} else {
		dp[n][m] = max(LCS(n - 1, m), LCS(n, m - 1));
	}
	return dp[n][m];
}

// RECONSTRUCTING THE LCS

void rec(int n, int m) {
	if (n < 0 or m < 0) return;
	if (travelSequence1[n] == travelSequence2[m]) {
		rec(n - 1, m - 1);
		cout << travelSequence1[n];
	} else {
		if (LCS(n, m - 1) > LCS(n - 1, m)) rec(n, m - 1);
		else rec(n - 1, m);
	}
}

int main() {
	int testCase = 1;
	while (true) {
		getline(cin, travelSequence1);
		if (travelSequence1[0] == '#') break;
		getline(cin, travelSequence2);
		memset(dp, -1, sizeof(dp));
		int answer = LCS(travelSequence1.size() - 1, travelSequence2.size() - 1);
		printf("Case #%d: you can visit at most %d cities.\n", testCase, answer);
		//printf("LCS: ");
		//rec(travelSequence1.size() - 1, travelSequence2.size() - 1);
		//printf("\n");
		testCase++;
	}
	return 0;
}
*/

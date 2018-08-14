//
// Created by ManuelLoaiza on 04/02/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 25;

int dp[MAX_N + 1][MAX_N + 1];
string matrix[MAX_N];

int main() {
	int testCases, n;
	bool firstTime = true;
	string input;
	cin >> testCases;
	
	while (testCases--) {
		if (firstTime) firstTime = false;
		else cout << endl;
		memset(dp, 0, sizeof(dp));
		cin >> matrix[0];
		n = matrix[0].size();
		for (int i = 1; i < n; i++) cin >> matrix[i];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
				if (matrix[i][j] == '1') dp[i + 1][j + 1]++;
			}
		}
		
		int numberOfOnes, expectedNumberOfOnes, answer = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int x = i; x <= n; x++) {
					for (int y = j; y <= n; y++) {
						numberOfOnes = dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1];
						expectedNumberOfOnes = (x - i + 1) * (y - j + 1);
						if (numberOfOnes == expectedNumberOfOnes) {
							answer = max(answer, numberOfOnes);
						}
					}
				}
			}
		}
		
		cout << answer << endl;
	}
	return 0;
}


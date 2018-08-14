//
// Created by Manuelloaiza on 03/04/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_DIGITS = 10;
const int MAX_SUM = 81;
long long dp[MAX_DIGITS][2][MAX_SUM + 1];
string a, b;

int digitSum(string &s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) sum += s[i] - '0';
	return sum;
}

long long digitDP(string &s, int index, int lower, int sum) {
	if (index == s.size()) return sum;
	if (dp[index][lower][sum] != -1) return dp[index][lower][sum];
	dp[index][lower][sum] = 0;
	int actualDigit = s[index] - '0';
	if (lower) {
		for (int i = 0; i <= 9; i++) dp[index][lower][sum] += digitDP(s, index + 1, 1, sum + i);
	} else {
		for (int i = 0; i <= actualDigit; i++) {
			if (i < actualDigit) dp[index][lower][sum] += digitDP(s, index + 1, 1, sum + i);
			else dp[index][lower][sum] += digitDP(s, index + 1, 0, sum + i);
		}
	}
	return dp[index][lower][sum];
}

int main() {
	long long answer;
	while (cin >> a >> b) {
		if (a[0] == '-') break;
		memset(dp, -1, sizeof(dp));
		answer = digitDP(b, 0, 0, 0);
		memset(dp, -1, sizeof(dp));
		answer -= digitDP(a, 0, 0, 0);
		answer += digitSum(a);
		printf("%lld\n", answer);
	}
}

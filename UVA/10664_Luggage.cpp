//
// Created by ManuelLoaiza on 03/29/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
const int MAX_SUM = 200;

int weight[MAX_N], dp[MAX_SUM + 1][MAX_N];

int numberOfWays(int actualSum, int index) {
	if (actualSum == 0) return 1;
	if (actualSum < 0) return 0;
	if (index < 0) return 0;
	if (dp[actualSum][index] != -1) return dp[actualSum][index];
	dp[actualSum][index] = numberOfWays(actualSum, index - 1) + numberOfWays(actualSum - weight[index], index - 1);
	return dp[actualSum][index];
}

int main() {
	int m, n, sum, half, ways;
	cin >> m;
	string input;
	getline(cin, input);
	
	while (m--) {
		getline(cin, input);
		stringstream ss(input);
		n = 0;
		sum = 0;
		
		while (ss >> weight[n]) {
			sum += weight[n];
			n++;
		}
		
		memset(dp, -1, sizeof(dp));
		if (sum % 2 == 0) {
			half = sum / 2;
			ways = numberOfWays(half, n - 1);
			if (ways > 0) cout << "YES" << endl;
			else cout << "NO" << endl;	
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}

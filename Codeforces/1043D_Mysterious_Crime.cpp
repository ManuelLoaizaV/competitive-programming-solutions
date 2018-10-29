//
// Created by ManuelLoaiza on 10/28/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, xd;
	cin >> n >> m;
	int ward[m][n];
	int f[n + 1];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> xd;
			if (i == 0) f[xd] = j + 1;
			ward[i][j] = f[xd];
		}
	}
	
	int dist[n + 1][m];
	for (int i = 0; i < m; i++) {
		dist[ward[i][0]][i] = 1;
		int x = 0;
		int y = 1;
		while (y < n) {
			if (ward[i][y] == ward[i][y - 1] + 1) {
				dist[ward[i][x]][i]++;
			} else {
				for (int j = x + 1; j < y; j++) dist[ward[i][j]][i] = dist[ward[i][j - 1]][i] - 1;
				dist[ward[i][y]][i] = 1;
				x = y;	
			}
			y++;
		}
		if (x < n - 1) for (int j = x + 1; j < n; j++) dist[ward[i][j]][i] = dist[ward[i][j - 1]][i] - 1;
	}
	
	ll answer = 0;
	if (n == 1) answer = (ll) n * ((ll) n + 1LL) / 2LL;
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == 0) xd = dist[i][j];
				else xd = min(xd, dist[i][j]);
			}
			answer = answer + xd;
		}	
	}
	cout << answer << endl;
	return 0;
}

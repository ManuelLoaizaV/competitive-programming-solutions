#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long Long;
const Long mod = 1000000007LL;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	string grid[h];
	for (int i = 0; i < h; i++) cin >> grid[i];
	Long dp[h + 1][w + 1];
	for (int i = 0; i <= h; i++) dp[i][0] = 0LL;
	for (int j = 0; j <= w; j++) dp[0][j] = 0LL;
	if (grid[0][0] == '.') dp[1][1] = 1LL;
	for (int row = 1; row <= h; row++) {
		for (int col = 1; col <= w; col++) {
			if (row == 1 and col == 1) continue;
			dp[row][col] = (dp[row][col - 1] + dp[row - 1][col]) % mod;
			if (grid[row - 1][col - 1] == '#') dp[row][col] = 0LL;
		}
	}
	cout << dp[h][w] << endl;
	return 0;
}
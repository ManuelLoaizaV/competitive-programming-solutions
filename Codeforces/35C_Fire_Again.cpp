#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;

struct Point {
	int x, y;
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	Point p[k];
	int h[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			h[i][j] = INF;
	for (int i = 0; i < k; i++) {
		cin >> p[i].x >> p[i].y;
		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= m; y++)
				h[x][y] = min(h[x][y], abs(p[i].x - x) + abs(p[i].y - y));
	}
	int maxi = h[1][1];
	Point answer;
	answer.x = 1;
	answer.y = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (h[i][j] > maxi) {
				answer.x = i;
				answer.y = j;
				maxi = h[i][j];
			}
	cout << answer.x << " " << answer.y << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
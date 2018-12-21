#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX_N = 2e+5;
vector<int> adj[MAX_N];
ll a[MAX_N], dp[MAX_N];
ll total, answer;
bool visited[MAX_N];

void dfs(int u, ll h) {
	visited[u] = true;
	dp[u] = a[u];
	total += (a[u] * h);
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			dfs(v, h + 1);
			dp[u] += dp[v];
		}
	}
}

void modify(int u, int v) {
	total -= dp[v];
	dp[u] -= dp[v];
	total += dp[u];
	dp[v] += dp[u];
}

void reroot(int u) {
	visited[u] = true;
	answer = max(answer, total);
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			modify(u, v);
			reroot(v);
			modify(v, u);
		}
	}
}

void solve() {
	int n, u, v;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	total = answer = 0LL;
	dfs(0, 0LL);
	memset(visited, 0, sizeof(visited));
	reroot(0);
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
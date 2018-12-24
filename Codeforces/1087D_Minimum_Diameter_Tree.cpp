#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAX_N = 1e+5;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int degree[MAX_N];

ll bfs(int s) {
	int leaves = 0;
	visited[s] = true;
	deque<int> p;
	p.pb(s);
	while (not p.empty()) {
		int u = p.front();
		p.pop_front();
		int l = adj[u].size();
		int sons = 0;
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			if (not visited[v]) {
				visited[v] = true;
				p.pb(v);
				sons++;
			}
		}
		if (sons == 0) leaves++;
	}
	return leaves;
}

void solve() {
	ll n, s;
	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
		degree[u]++;
		degree[v]++;
	}
	int root, maxDegree;
	for (int i = 0; i < n; i++) {
		if (i == 0 or degree[i] > maxDegree) {
			root = i;
			maxDegree = degree[i];
		}
	}
	ld answer = (ld) s;
	if (n > 2) answer *= 2.0L / ((ld) bfs(root));
	cout << fixed << setprecision(18) << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
using namespace std;

const int MAX_N = 1e5;
vector<int> adj[MAX_N + 1];
bool visited[MAX_N + 1];
int h[MAX_N + 1];

void DFS(int u) {
	visited[u] = true;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) DFS(v);
		h[u] = max(h[u], 1 + h[v]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++) {
		if (not visited[i]) DFS(i);
	}
	int answer = 0;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, h[i]);
	}
	cout << answer << endl;
	return 0;
}
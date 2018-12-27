#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cout << #x << x << endl
#define pb push_back
using namespace std;
const int MAX_N = 2e+5;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int anc[MAX_N];
int h[MAX_N];
int answer = 0;
int node;
bool belowNode = false;

void dfs(int u) {
	visited[u] = true;
	if (belowNode) answer = max(answer, h[u]);
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			if (v == node) belowNode = true;
			dfs(v);
			if (v == node) belowNode = false;
		}
	}
}

void dfs(int u, int p) {
	visited[u] = true;
	anc[u] = p;
	if (p == -1) h[u] = 0;
	else h[u] = h[p] + 1;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) dfs(v, u);
	}
}

void solve() {
	int n, x;
	cin >> n >> x;
	x--;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0, -1);
	// Primero hallo el maximo numero de pasos que puede subir Bob
	int steps = (h[x] - 1) / 2;
	// Luego, hallo el maximo nodo al cual Bob puede subir
	node = x;
	while (steps--) node = anc[node];
	// Finalmente hallo la maxima profundidad que Alice puede alcanzar
	// pasando por aquel nodo
	memset(visited, 0, sizeof(visited));
	dfs(0);
	answer *= 2;
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int N = 1e4 + 5;
bool ok = true;
int deg[N], c[N];
vector<int> adj[N];

void DFS(int u) {
	c[u]++;
	for (int v : adj[u]) {
		if (c[v] == 0) DFS(v);
		else if (c[v] == 1) ok = false;
	}
	c[u]++;
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) if (c[i] == 0) DFS(i);
	if (not ok) {
		cout << "Sandro fails." << endl;
		return 0;
	}
	vector<int> order;
	set<pair<int, int>> aux;
	for (int i = 1; i <= n; i++) aux.insert({deg[i], i});
	for (int i = 0; i < n; i++) {
		pair<int, int> fst = (*aux.begin());
		aux.erase(fst);
		int u = fst.second;
		order.push_back(u);
		for (int v : adj[u]) {
			int f = deg[v];
			pair<int, int> snd = {f, v};
			aux.erase(snd);
			deg[v]--;
			snd.first--;
			aux.insert(snd);
		}
	}
	for (int i = 0; i < n; i++) cout << order[i] << " ";
	return 0;
}
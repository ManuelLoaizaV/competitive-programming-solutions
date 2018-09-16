//
// Created by ManuelLoaiza on 09/16/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+3;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int vertex[MAX_N], edges[MAX_N];
int comp;

void initialize() {
	for (int i = 0; i < MAX_N; i++) {
		adj[i].clear();
		visited[i] = false;
		vertex[i] = 0;
		edges[i] = 0;
	}
	comp = 0;
}

void DFS(int u) {
	visited[u] = true;
	vertex[comp]++;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		edges[comp]++;
		if (not visited[v]) DFS(v);
	}
}

void solve() {
	initialize();
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 0; i < n; i++) {
		if (not visited[i]) {
			DFS(i);
			comp++;
		}
	}
	
	bool loop = false;
	for (int i = 0; i < comp; i++) {
		edges[i] /= 2;
		if (edges[i] >= vertex[i]) {
			loop = true;
			break;
		}	
	}
	if (loop) cout << "1" << endl;
	else cout << "0" << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}


//
// Created by ManuelLoaiza on 06/01/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
const int INF = 1e+9;

vector <int> adj[MAX_N], cost[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

void createGraph(int n, int m) {
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		visited[i] = false;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		cost[x].push_back(0);
		adj[y].push_back(x);
		cost[y].push_back(1);
	}
}

void BFS01(int s) {
	dist[s] = 0;
	deque <int> path;
	path.push_back(s);
	while (not path.empty()) {
		int u = path.front();
		path.pop_front();
		if (visited[u]) continue;
		visited[u] = true;
		int l = adj[u].size();
		for (int i = 0; i < l; i++) {
			int v = adj[u][i];
			int w = cost[u][i];
			int temp = dist[u] + w;
			if (temp < dist[v]) {
				dist[v] = temp;
				if (w == 0) path.push_front(v);
				else path.push_back(v);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	createGraph(n, m);
	BFS01(0);
	if (dist[n - 1] == INF) cout << "-1" << endl;
	else cout << dist[n - 1] << endl;
	return 0;
}


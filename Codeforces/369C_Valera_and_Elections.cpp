#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;

bool visited[MAX_N];
int state[MAX_N];
int problemSons[MAX_N];
vector <int> adj[MAX_N];

void DFS(int u) {
	visited[u] = true;
	int l = adj[u].size();
	for (int i = 0; i < l; i++) {
		int v = adj[u][i];
		if (not visited[v]) {
			if (state[v] == 2) problemSons[u]++;
			DFS(v);
			problemSons[u] += problemSons[v];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		state[u] = max(state[u], t);
		state[v] = max(state[v], t);
	}
	DFS(0);
	vector <int> answer;
	for (int i = 0; i < n; i++) {
		if (state[i] == 2 and problemSons[i] == 0) answer.push_back(i + 1);
	}
	int l = answer.size();
	cout << l << endl;
	for (int i = 0; i < l; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}
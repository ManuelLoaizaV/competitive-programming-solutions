#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 105;
vector<int> adj[N], order;
bool used[N];

void DFS(int u) {
	used[u] = true;
	for (int v : adj[u]) if (not used[v]) DFS(v);
	order.push_back(u);
}

int main() {
	fastio;
	int n, m;
	//bool fst = true;
	while (true) {
		cin >> n >> m;
		if (n == 0 and m == 0) break;
		//if (fst) fst = false;
		//else cout << endl;
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++) if (not used[i]) DFS(i);
		for (int i = 0; i < n; i++) {
			if (i > 0) cout << " ";
			cout << order[n - 1 - i];
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			used[i] = false;
		}
		order.clear();
	}
	return 0;
}
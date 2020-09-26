#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 1e5;
const int INF = 1e9;
vector<vector<pair<int, int>>> adj;
vector<int> dp;
int target;
// Encontrar el camino maximo en un grafo es NP
// Sin embargo, en este caso particular de ser un DAG es O(V + E)

// Distancia maxima de u a target, para todo u
int DP(int u) {
  // Caso base
  if (u == target) return 0;
  if (dp[u] != -1) return dp[u];
  dp[u] = -INF;
  for (pair<int, int> edge : adj[u]) {
    int v = edge.first;
    int w = edge.second;
    dp[u] = max(dp[u], DP(v) + w);
  }
  // En dp[u] queda el maximo camino para llegar a target
  return dp[u];
}

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 0; i <= n; i++) dp[i] = -1;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  cin >> target;
  for (int i = 1; i <= n; i++)
    printf("Distancia maxima desde %d a %d: %d.\n", i, target, DP(i));
  return 0;
}

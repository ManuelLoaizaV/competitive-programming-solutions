#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> dp;
int target;

// Distancia minima de u hacia target cuando me sobran k cupones
// O(10(V + E))
int DP(int u, int k) {
  if (u == target) return 0;
  if (dp[u][k] != -1) return dp[u][k];
  dp[u][k] = INF;
  for (pair<int, int> edge : adj[u]) {
    int v = edge.first;
    int w = edge.second;
    dp[u][k] = min(dp[u][k], DP(v, k) + w);
    if (k > 0) dp[u][k] = min(dp[u][k], DP(v, k - 1));
  }
  return dp[u][k];
}

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  dp.resize(n + 1);
  for (int i = 0; i <= n; i++) dp[i].resize(11);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 10; j++)
      dp[i][j] = -1;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  cin >> target;
  int cupones = 1;
  for (int i = 1; i <= n; i++)
    printf("Distacia minima de %d a %d usando a lo mas %d cupones: %d.\n",
        i, target, cupones, DP(i, cupones));
  return 0;
}

#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
vector<vector<int>> adj;
vector<int> dp;
int target;

// Cantidad de caminos de u a target, para todo u
int DP(int u) {
  // Caso base
  if (u == target) return 1;
  if (dp[u] != -1) return dp[u];
  dp[u] = 0;
  for (int v : adj[u]) {
    dp[u] += DP(v);
  }
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
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  cin >> target;
  for (int i = 1; i <= n; i++)
    printf("Cantidad de caminos de %d a %d: %d\n", i, target, DP(i));
  return 0;
}

#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 5e4; // Importante
vector<vector<int>> adj;
bitset<N> dp[N];
bool used[N];

// Cantidad y cuales nodos alcanzables para cada nodo
// Con bitset tenemos O(n^2 / 64)

bitset<N>  DP(int u) {
  if (used[u]) return dp[u];
  dp[u].set(u);
  for (int v : adj[u])
    dp[u] |= DP(v);
  used[u] = true;
  return dp[u];
}

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  for (int i = 0; i < n; i++)
    printf("Cantidad de nodos alcanzables desde %d: %d.\n", i, DP(i).count());
  return 0;
}

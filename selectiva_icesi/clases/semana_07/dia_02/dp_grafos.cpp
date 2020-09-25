#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 1e5;
vector<vector<pair<int, int>> adj;
int dp[N];
int target;
// Encontrar el camino maximo en un grafo es NP
// Sin embargo, en este caso particular de ser un DAG es O(V + E)

// Distancia maxima de u a target, para todo u
int DP_DistanciaMaxima(int u) {
  // Caso base
  if (u == target) return 0;
  if (dp[u] != -1) return dp[u];
  dp[u] = -INF;
  for (pair<int, int> edge : adj[u]) {
    int v = edge.first;
    int w = edge.second;
    dp[u] = min(dp[u], DP(v) + w);
  }
  // En dp[u] queda el maximo camino para llegar a target
  return dp[u];
}

// Cantidad de caminos de u a target, para todo u
int DP_CantidadCaminos(int u) {
  // Caso base
  if (u == target) return 1;
  if (dp[u] != -1) return dp[u];
  dp[u] = 0;
  for (pair<int, int> edge : adj[u]) {
    int v = edge.first;
    int w = edge.second;
    dp[u] += DP(v);
  }
  // En dp[u] queda el maximo camino para llegar a target
  return dp[u];
}

// TODO: Completar ruta minima con k cupones
// O(10(V + E))
int dp[N][11];
int DP(int u, int k) {
  if (u == T) return 0;
  if (dp[u] != -1) return dp[u];
  for (pair<int, int> edge : adj[u]) {
    dp[u][k] = min();
  }
}

// TODO: Completar cantidad de nodos alcanzables para cada nodo
// Con bitset tenemos O(n^2 / 64)
bitset<N> dp[N];
bool used[N];
int DP_CantidadAlcanzables(int u) {
  if (used[u]) return dp[u];

}

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  adj.assign(n + 1, ());
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  cin >> target;
  memset(dp, -1, sizeof(dp));
  // TODO: Completar llamada a funciones y testearlas
  return 0;
}

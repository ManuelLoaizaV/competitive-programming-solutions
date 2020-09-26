#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int INF = 1e9;
vector<vector<pair<int, int>>> adj;

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<int> d(n + 1, INF);
  d[1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, 1});  // Al nodo 1 se llega con distancia 0
  while (q.size()) {
    int u = q.top().second;
    int w = q.top().first;
    q.pop();
    // Verificar que este no es el mejor de llegar a u
    if (d[u] != w) continue;
    // la arista pertenece al dijkstra tree u w
    for (pair<int, int> e : adj[u]) {
      int v = e.first;
      int nw = w + e.second;
      // Relajamos sus vecinos
      if (nw < d[v]) {
        d[v] = nw;
        q.push({d[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++)
    printf("Distancia minima de 1 a %d: %d.\n", i, d[i]);
  return 0;
}

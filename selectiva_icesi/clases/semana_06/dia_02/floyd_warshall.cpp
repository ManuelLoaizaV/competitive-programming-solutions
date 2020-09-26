#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
const int INF = 1e9;

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
  vector<vector<int>> p(n + 1, vector<int>(n + 1, -1));
  for (int i = 1; i <= n; i++) d[i][i] = 0;  // Caso base con uno mismo
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = min(d[u][v], w);  // Caso base sin nodos entre ellos
    // d[v][u] = min(d[v][u], w);
    p[u][v] = u;  // El padre de v respecto a u
    // p[v][u] = v;
  }

  for (int k = 1; k <= n; k++) {  // Calculado para nodos <= k en dicho momento
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        // f(i, j, k) = min(f(i, j, k - 1), f(i, k, k - 1) + f(k, j, k - 1))
        // d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        // Si me piden reconstruir camino
        if (d[i][k] + d[k][j] < d[i][j]) {
          d[i][j] = d[i][k] + d[k][j];
          // Si quiero ir de i a j, el padre de j respecto a i
          // tiene que ser el padre de j respecto a k
          p[i][j] = p[k][j];
        }
      }
    }
  }

  int u, v;
  cout << "Ingrese el nodo de partida y el nodo destino: ";
  cin >> u >> v;
  int v_ = v;
  printf("Distancia minima de %d a %d: %d.\n", u, v, d[u][v]);
  vector<int> path;
  path.push_back(v);
  while (u != v) {
    int pv = p[u][v];
    path.push_back(pv);
    v = pv;
  }
  printf("Camino minimo desde %d a %d:\n", u, v_);
  reverse(path.begin(), path.end());
  for (int i = 0; i < path.size(); i++) {
    if (i > 0) cout << " -> ";
    cout << path[i];
  }
  cout << '\n';
  return 0;
}

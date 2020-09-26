#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;
const int INF = 1e9;
vector<vector<int>> adj;

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  struct Edge {
    int u, v, w;
  };
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back({a, b, w});
  }
  vector<int> d(n + 1, INF);
  d[1] = 0;
  // Numero de iteraciones que vamos a hacer del algoritmo
  for (int i = 0; i < n - 1; i++) {
    for (Edge e : edges) {
      d[e.v] = min(d[e.v], d[e.u] + e.w);
    }
  }
  // Determinar ciclos negativos
  for (Edge e : edges) {
    if (d[e.u] + e.w < d[e.v]) {
      cout << "Ciclo negativo encontrado." << '\n';
      return 0;
    }
  }
  // Imprimimos las distancias minimas
  for (int i = 1; i <= n; i++)
    printf("Distancia minima de 1 a %d: %d.\n", i, d[i]);
  return 0;
}

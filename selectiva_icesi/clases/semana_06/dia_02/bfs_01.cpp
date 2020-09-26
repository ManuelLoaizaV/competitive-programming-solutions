#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
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
  deque<pair<int, int>> q;
  vector<int> d(n + 1, INF);
  q.push_back({1, 0});
  d[1] = 0;
  while (q.size()) {
    int u = q.front().first;
    int cost = q.front().second;
    q.pop_front();
    if (d[u] != cost) continue;
    for (pair<int, int> e : adj[u]) {
      int v = e.first;
      int w = e.second;
      if (w + d[u] < d[v]) {
        d[v] = w + d[u];
        if (w == 0) q.push_front({v, d[v]});
        else q.push_back({v, d[v]});
      }
    }
  }
  for (int i = 1; i <= n; i++)
    printf("Distancia minima de 1 a %d: %d.\n", i, d[i]);
  return 0;
}

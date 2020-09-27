// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> d(n + 1, -1);
  queue<int> q;
  d[1] = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  cout << d[n] - 1 << '\n';
  return 0;
}

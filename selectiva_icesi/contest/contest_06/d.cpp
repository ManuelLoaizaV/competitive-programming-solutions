// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int N = 100;
vector<int> adj[N + 1];
int in[N + 1];

void TopologicalSort(int n) {
  queue<int> q;
  for (int i = 1; i <= n; i++) if (in[i] == 0) q.push(i);
  int cnt = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (cnt > 0) cout << " ";
    cout << u;
    cnt++;
    for (int v : adj[u]) {
      in[v]--;
      if (in[v] == 0) q.push(v);
    }
  }
  cout << '\n';
}

int main() {
  FAST_IO;
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      in[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      in[v]++;
    }
    TopologicalSort(n);
  }
  return 0;
}

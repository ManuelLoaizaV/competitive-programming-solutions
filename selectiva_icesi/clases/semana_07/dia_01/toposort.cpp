#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void TopologicalSort(int n, int m, vector<vector<int>>& g, vector<int> in_deg) {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (in_deg[i] == 0) q.push(i);
  while (q.size()) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v : g[u]) {
      in_deg[v]--;
      if (in_deg[v] == 0) {
        q.push(v);
      }
    }
  }
  cout << '\n';
}

void TopologicalSortLex(int n, int m, vector<vector<int>>& g, vector<int> in_deg) {
  priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (int i = 1; i <= n; i++)
    if (in_deg[i] == 0) pq.push(i);
  while (pq.size()) {
    int u = pq.top();
    pq.pop();
    cout << u << " ";
    for (int v : g[u]) {
      in_deg[v]--;
      if (in_deg[v] == 0) {
        pq.push(v);
      }
    }
  }
  cout << '\n';
}

void DFS(int u, stack<int>& st, vector<vector<int>>& g, vector<bool>& used) {
  used[u] = true;
  for (int v : g[u])
    if (!used[v]) DFS(v, st, g, used);
  st.push(u);
}

void TopologicalSortDFS(int n, int m, vector<vector<int>>& g, vector<bool> used) {
  stack<int> res;
  for (int i = 1; i <= n; i++)
    if (!used[i]) DFS(i, res, g, used);
  while (res.size()) {
    cout << res.top() << " ";
    res.pop();
  }
  cout << '\n';
}

int main() {
  FAST_IO;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<int> in_deg(n + 1);
  vector<bool> used(n + 1);
  for (int i = 0; i <= n; i++) used[i] = false;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    in_deg[b]++;
  }
  cout << "Grafo:" << '\n';
  for (int i = 1; i <= n; i++) {
    cout << i << ": ";
    for (int j = 0; j < g[i].size(); j++) {
      if (j > 0) cout << ", ";
      cout << g[i][j];
    }
    cout << '\n';
  }
  cout << "Algun ordenamiento topologico:" << '\n';
  TopologicalSort(n, m, g, in_deg);
  cout << "El ordenamiento topologico menor lexicografico:" << '\n';
  TopologicalSortLex(n, m, g, in_deg);
  cout << "Algun ordenamiento topologico usando DFS:" << '\n';
  TopologicalSortDFS(n, m, g, used);
  return 0;
}

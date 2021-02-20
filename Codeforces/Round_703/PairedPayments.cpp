//https://codeforces.com/contest/1486/problem/E
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef int Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, int> Pair;

const int N = 51e5;
const int W = 50;
const Long INF = 1e9 + 7;
const Double EPS = 1e-9;

vector<pair<int, Long>> adj[N];
Long d[N];
// 0 .. n - 1
// Nuevo {
// 1: 0 .. n - 1
// 2: 0 .. n - 1
// . . .
// 50: 0 .. n - 1
// }

int GetVal(int u, Long w, int n) {
  return w * n + u;
}

void AddEdge(int u, int v, Long w1, int n) {
  int v2 = GetVal(v, w1, n);
  adj[u].push_back({v2, 0});
  for (Long w2 = 1; w2 <= W; w2++) {
    int u2 = GetVal(u, w2, n);
    adj[u2].push_back({v, (w1 + w2) * (w1 + w2)});
  }
}

void Dijkstra(int s, int n) {
  for (int i = 0; i < n; i++) {
    for (int w = 0; w <= W; w++) {
      d[w * n + i] = INF;
    }
  }
  priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
  d[s] = 0;
  pq.push({d[s], s});
  while (!pq.empty()) {
    Pair path = pq.top();
    pq.pop();
    int u = path.second;
    if (d[u] != path.first) continue;
    for (Pair e : adj[u]) {
      int v = e.first;
      Long w = e.second;
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        pq.push({d[v], v});
      }
    }
  }
}

void Solve(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    Long w;
    cin >> u >> v >> w;
    u--;
    v--;
    AddEdge(u, v, w, n);
    AddEdge(v, u, w, n);
  }
  // Creo las aristas intermedias
  Dijkstra(0, n);
  for (int i = 0; i < n; i++) {
    if (d[i] == INF) {
      cout << -1 << " ";
    } else {
      cout << d[i] << " ";
    }
  }
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


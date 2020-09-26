// Gracias, Osman
#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef pair<int, int> Pair;

const int N = 1e3;
const int INF = 1e9;

vector<Pair> adj[N * N];
vector<Pair> mv = {{0, -1}, {1, 0}};
string g[N];
int r, c;

int f(int i, int j) {
  return (i * c + j);
}

bool ok(int i, int j) {
  if (0 <= i && i < r && 0 <= j && j < c) return true;
  return false;
}

void Solve() {
  cin >> r >> c;
  int n = r * c;
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < r; i++) cin >> g[i];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < 2; k++) {
        int x = i + mv[k].first;
        int y = j + mv[k].second;
        if (ok(x, y)) {
          int f1 = f(i, j);
          int f2 = f(x, y);
          int w = !(g[i][j] == g[x][y]);
          adj[f1].push_back({f2, w});
          adj[f2].push_back({f1, w});
        }
      }
    }
  }

  vector<int> d(n, INF);
  d[0] = 0;
  deque<Pair> q;
  q.push_back({0, 0});
  while (q.size()) {
    int u = q.front().first;
    int d_u = q.front().second;
    q.pop_front();
    if (d[u] != d_u) continue;
    for (pair<int, int> e : adj[u]) {
      int v = e.first;
      int w = e.second;
      if (d_u + w < d[v]) {
        d[v] = d_u + w;
        if (w == 0) q.push_front({v, d[v]});
        else q.push_back({v, d[v]});
      }
    }
  }
  cout << d[n - 1] << '\n';
}

int main() {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}

//https://codeforces.com/contest/1487/problem/E
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<int, Long> Pair;

const int N = 15e4;
const Long INF = 1e16;
const Double EPS = 1e-9;

struct SegmentTree {
  bool marked[4 * N];
  Long lazy[4 * N];
  void Build(int id, int tl, int tr) {
    marked[id] = false;
    if (tl == tr) {
      lazy[id] = INF;
    } else {
      int tm = (tl + tr) / 2;
      Build(2 * id, tl, tm);
      Build(2 * id + 1, tm + 1, tr);
    }
  }
  void Push(int id) {
    if (marked[id]) {
      // Asignar
      lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
      marked[2 * id] = marked[2 * id + 1] = true;
      // Reiniciar
      marked[id] = false;
    }
  }
  void Update(int l, int r, Long val, int id, int tl, int tr) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
      // Asignar
      lazy[id] = val;
      marked[id] = true;
    } else {
      Push(id);
      int tm = (tl + tr) / 2;
      Update(l, r, val, 2 * id, tl, tm);
      Update(l, r, val, 2 * id + 1, tm + 1, tr);
    }
  }
  Long Query(int pos, int id, int tl, int tr) {
    if (tl == tr) return lazy[id];
    int tm = (tl + tr) / 2;
    Push(id);
    if (pos <= tm) return Query(pos, 2 * id, tl, tm);
    return Query(pos, 2 * id + 1, tm + 1, tr);
  }
} st;

bool Decreasing(const Pair& p1, const Pair& p2) {
  return p1.second > p2.second;
}

void Solve(void) {
  vector<int> n(4);
  for (int i = 0; i < 4; i++) cin >> n[i];
  vector<vector<Pair>> a(4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n[i]; j++) {
      Long x;
      cin >> x;
      a[i].push_back({j, x});
    }
  }
  vector<vector<int>> adj[3];
  for (int i = 0; i < 3; i++) {
    adj[i].resize(n[i + 1]);
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[i][v].push_back(u);
    }
    for (int j = 0; j < n[i + 1]; j++) sort(adj[i][j].begin(), adj[i][j].end());
  }
  for (int i = 2; i >= 0; i--) {
    st.Build(1, 0, n[i] - 1);
    sort(a[i + 1].begin(), a[i + 1].end(), Decreasing);
    for (int j = 0; j < n[i + 1]; j++) {
      int pos = a[i + 1][j].first;
      int len = adj[i][pos].size();
      if (len == 0) {
        st.Update(0, n[i] - 1, a[i + 1][j].second, 1, 0, n[i] - 1);
        continue;
      }
      // El primer segmento
      if (adj[i][pos][0] > 0) {
        st.Update(0, adj[i][pos][0] - 1, a[i + 1][j].second, 1, 0, n[i] - 1);
      }
      for (int k = 0; k < len - 1; k++) {
        if (adj[i][pos][k + 1] - adj[i][pos][k] > 1) {
          st.Update(adj[i][pos][k] + 1, adj[i][pos][k + 1] - 1, a[i + 1][j].second, 1, 0, n[i] - 1);
        }
      }
      // El ultimo segmento
      if (adj[i][pos][len - 1] < n[i] - 1) {
        st.Update(adj[i][pos][len - 1] + 1, n[i] - 1, a[i + 1][j].second, 1, 0, n[i] - 1);
      }
    }
    for (int j = 0; j < n[i]; j++) {
      a[i][j].second += st.Query(j, 1, 0, n[i] - 1);
    }
  }
  Long ans = INF;
  for (int i = 0; i < n[0]; i++) ans = min(ans, a[0][i].second);
  if (ans >= INF) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


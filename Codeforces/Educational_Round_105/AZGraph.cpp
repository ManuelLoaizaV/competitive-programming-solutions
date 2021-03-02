//https://codeforces.com/contest/1494/problem/E
#include <bits/stdc++.h>

using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;
const Long MOD = 1e9 + 7;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<map<int, int>> adj(n);
  Long pairs, equal_pairs;
  pairs = equal_pairs = 0;
  while (m--) {
    char t;
    cin >> t;
    if (t == '?') {
      int k;
      cin >> k;
      if (k & 1) {
        cout << ((pairs > 0) ? "YES" : "NO") << '\n';
      } else {
        cout << ((equal_pairs > 0) ? "YES" : "NO") << '\n';
      }
    } else if (t == '+') {
      int u, v;
      char c;
      cin >> u >> v >> c;
      u--; v--;
      adj[u][v] = c;
      if (adj[v].count(u) > 0) {
        pairs++;
        if (adj[v][u] == c) equal_pairs++;
      }
    } else {
      int u, v;
      cin >> u >> v;
      u--; v--;
      char c = adj[u][v];
      adj[u].erase(v);
      if (adj[v].count(u) > 0) {
        pairs--;
        if (adj[v][u] == c) equal_pairs--;
      }
    }
  }
  return 0;
}


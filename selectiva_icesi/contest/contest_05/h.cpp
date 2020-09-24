#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef long long Long;

vector<vector<int>> adj;
set<pair<int, pair<int, int>>> trio;  // Tripletas prohibidas

void Print(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << '\n';
}

void BFS() {
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {0, 0}});
  dist[0][0] = 1LL;
  while (!q.empty()) {
    Long d = q.front().first;
    Long p_pos = q.front().second.first;
    Long pos = q.front().second.second;

  }
}

int main() {
  FAST_IO;
  Long n, m, k;
  cin >> n >> m >> k;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // Prohibido visitar estas tripletas
  for (int i = 0; i < k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    trio.insert({a, {b, c}});
  }
  BFS();
  return 0;
}

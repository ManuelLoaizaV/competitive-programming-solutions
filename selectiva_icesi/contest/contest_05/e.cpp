// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair;

const Long INF = 1e12;

vector<vector<Pair>> adj;

int main() {
  FAST_IO;
  Long n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  while (m--) {
    Long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<Long> d(n + 1, INF);
  vector<Long> p(n + 1, -1);
  d[1] = 0LL;
  priority_queue<Pair, vector<Pair>, greater<Pair>> q;
  q.push({0, 1});
  while (q.size()) {
    Long u = q.top().second;
    Long w = q.top().first;
    q.pop();
    if (d[u] != w) continue;
    for (Pair e : adj[u]) {
      Long v = e.first;
      Long nw = w + e.second;
      if (nw < d[v]) {
        d[v] = nw;
        p[v] = u;
        q.push({d[v], v});
      }
    }
  }
  if (d[n] >= INF) {
    cout << -1 << '\n';
  } else {
    Long cur = n;
    stack<Long> ans;
    while (cur != -1) {
      ans.push(cur);
      cur = p[cur];
    }
    while(ans.size()) {
      cout << ans.top() << " ";
      ans.pop();
    }
    cout << '\n';
  }
  return 0;
}

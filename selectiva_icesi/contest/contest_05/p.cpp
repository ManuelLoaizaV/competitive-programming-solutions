// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
#define x first
#define y second
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const Double EPS = 1e-9;
const Long INF = 1e18;
const Long N = 2e2;

vector<Long> adj[N];
Long n;
Pair p[N];
bool used[N];

Double Dist(Pair& a, Pair& b) {
  Long dx = a.x - b.x;
  Long dy = a.y - b.y;
  return (sqrt((Double)(dx * dx + dy * dy)));
}

bool BFS(Long s, Double limit) {
  for (int i = 0; i < n; i++) used[i] = false;
  queue<Long> q;
  used[s] = true;
  q.push(s);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (Long v : adj[u]) {
      if (!used[v] && (Dist(p[u], p[v]) <= limit)) {
        used[v] = true;
        q.push(v);
      }
    }
  }
  return used[1];
}

Double Solve() {
  for (int i = 0; i < n; i++) adj[i].clear();
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }
  Double l = 0.0;
  Double r = Dist(p[0], p[1]);
  while (r - l > EPS) {
    Double m = (l + r) / 2;
    if (BFS(0, m)) r = m;
    else l = m;
  }
  return ((l + r) / 2);
}

int main() {
  FAST_IO;
  int t = 1;
  while (cin >> n) {
    if (n == 0) break;
    cout << "Scenario #" << t << '\n';
    cout << "Frog Distance = " << fixed << setprecision(3) << Solve() << '\n';
    cout << '\n';
    t++;
  }
  return 0;
}

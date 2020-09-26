// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef pair<int, int> Pair;

const int N = 20;

vector<int> adj[N * N];
string g[N];
int w, h;
bool used[N * N];

int f(int i, int j) {
  return (h * i + j);
}

bool ok(int i, int j) {
  if (0 <= i && i < w && 0 <= j && j < h
      && (g[i][j] == '.' || g[i][j] == '@')) return true;
  return false;
}

int Solve() {
  cin >> h >> w;
  for (int i = 0; i < w; i++) cin >> g[i];
  int n = w * h;
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    used[i] = false;
  }
  
  vector<Pair> move = {{0, -1}, {1, 0}};
  int ini;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (g[i][j] == '@') ini = f(i, j);
      for (int k = 0; k < 2; k++) {
        int x = i + move[k].first;
        int y = j + move[k].second;
        if (ok(x, y) && ok(i, j)) {
          int u = f(x, y);
          int v = f(i, j);
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
      }
    }
  }

  queue<int> q;
  q.push(ini);
  used[ini] = true;
  int cnt = 0;
  while (q.size()) {
    int u = q.front();
    cnt++;
    q.pop();
    for (int v : adj[u]) {
      if (!used[v]) {
        used[v] = true;
        q.push(v);
      }
    }
  }
  return cnt;
}

int main() {
  FAST_IO;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    printf("Case %d: %d\n", i, Solve());
  }
  return 0;
}

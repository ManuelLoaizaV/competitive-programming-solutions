// Gracias, Osman
#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef pair<int, int> Pair;

const int N = 100;

vector<int> adj[N * N];
bool used[N * N];
string g[N];
int n, m;

void DFS(int u) {
  used[u] = true;
  for (int v : adj[u]) if (!used[v]) DFS(v);
}

bool ok(int i, int j) {
  if (0 <= i && i < n && 0 <= j && j < m && g[i][j] == '@') return true;
  return false;
}

int f(int i, int j) {
  return (i * m + j);
}

int main() {
  FAST_IO;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    int total = n * m;
    for (int i = 0; i < total; i++) {
      adj[i].clear();
      used[i] = false;
    }
    for (int i = 0; i < n; i++) cin >> g[i];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int x = i + dx;
            int y = j + dy;
            if (ok(x, y) && ok(i, j)) {
              int f1 = f(i, j);
              int f2 = f(x, y);
              adj[f1].push_back(f2);
              adj[f2].push_back(f1);
            }
          }
        }
      }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int f1 = f(i, j);
        if (!used[f1] && ok(i, j)) {
          cnt++;
          DFS(f1);
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

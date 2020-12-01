//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define debug(x) cout << #x << " = " << x << endl
#define all(v) (v).begin(),(v).end()
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 3e5;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<int> adj[N + 1];
bool is_used[N + 1];
bool in_cycle[N + 1];
bool is_done;
stack<int> tour;
vector<int> cycle;

void DFS(int u, int p) {
  is_used[u] = true;
  tour.push(u);
  for (int v : adj[u]) {
    if (v != p) {
      if (!is_used[v]) {
        DFS(v, u);
      } else {
        // encontre el ciclo
        if (is_done) break;
        while (true) {
          int last = tour.top();
          if (last == v) break;
          cycle.push_back(last);
          in_cycle[last] = true;
          tour.pop();
        }
        cycle.push_back(v);
        in_cycle[v] = true;
        tour.pop();
        is_done = true;
      }
    }
  }
  if (!tour.empty()) tour.pop();
}

Long Count(int u) {
  is_used[u] = true;
  Long cnt = 1LL;
  for (int v : adj[u]) if (!is_used[v] && !in_cycle[v]) cnt += Count(v);
  return cnt;
}

void Initialize(int n) {
  cycle.clear();
  is_done = false;
  while (!tour.empty()) tour.pop();
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    is_used[i] = false;
    in_cycle[i] = false;
  }
}

void Solve(void) {
  int n;
  cin >> n;
  Initialize(n);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1, -1);
  // reinicio para contar
  for (int i = 1; i <= n; i++) is_used[i] = false;
  Long len = cycle.size();
  Long ans = 0LL;
  for (int u : cycle) {
    bool is_root = false;
    for (int v : adj[u]) {
      if (!is_used[v] && !in_cycle[v]) {
        Long cnt = Count(u);
        ans += (cnt * (cnt - 1) / 2LL);
        ans += (cnt * (n - cnt));
        is_root = true;
        break;
      }
    }
    if (!is_root) ans += (n - 1);
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}

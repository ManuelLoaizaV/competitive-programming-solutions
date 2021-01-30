//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define all(v) (v).begin(),(v).end()
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 2e5;
const int K = 17;
const Long INF = 1e9;

int GetBit(int mask, int bit) { return (mask >> bit) & 1; }
void TurnOn(int& mask, int bit) { mask = mask | (1 << bit); }
void TurnOff(int& mask, int bit) { mask = mask & (~(1 << bit)); }

vector<int> gems;

struct Graph {
  vector<int> adj[N];
  Long d[N][K];
  void AddEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void BFS(int id_s, int n) {
    int s = gems[id_s];
    for (int i = 0; i < n; i++) d[i][id_s] = INF;
    d[s][id_s] = 0;
    deque<int> tour;
    tour.push_back(s);
    while (!tour.empty()) {
      int u = tour.front();
      tour.pop_front();
      for (int v : adj[u]) {
        if (d[v][id_s] == INF) {
          d[v][id_s] = d[u][id_s] + 1;
          tour.push_back(v);
        }
      }
    }
  }
} g;

int k;
Long dp[1 << K][K];
bool is_done[1 << K][K];

// DP(mask, last): minima cantidad de piedras para convertir mask a 11..11 habiendo
// teniendo como ultima piedra a last.
Long DP(int mask, int last) {
  if (mask == ((1 << k) - 1)) return 0;
  if (is_done[mask][last]) return dp[mask][last];
  dp[mask][last] = INF;
  for (int bit = 0; bit < k; bit++) {
    if (GetBit(mask, bit) == 0) {
      int new_mask = mask;
      TurnOn(new_mask, bit);
      dp[mask][last] = min(dp[mask][last], g.d[gems[bit]][last] + DP(new_mask, bit));
    }
  }
  is_done[mask][last] = true;
  return dp[mask][last];
}

void Solve(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g.AddEdge(u, v);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    c--;
    gems.push_back(c);
  }
  for (int i = 0; i < k; i++) g.BFS(i, n);
  Long ans = INF;
  for (int i = 0; i < k; i++) {
    Long tmp = 1LL + DP(1 << i, i);
    ans = min(ans, tmp);
  }
  if (ans < INF) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


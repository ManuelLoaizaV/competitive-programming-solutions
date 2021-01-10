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
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

vector<int> adj[N];

int a[N];
int in[N], out[N], parent[N];
vector<int> pos_in[N];

void CoordinateCompression(int n) {
  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; i++) pairs.push_back({a[i], i});
  sort(pairs.begin(), pairs.end());
  int nxt = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && pairs[i].first != pairs[i - 1].first) nxt++;
    a[pairs[i].second] = nxt;
  }
}

int timer = 0;
void DFS(int u, int p = -1) {
  parent[u] = p;
  // Momento en el cual un nodo fue visitado
  in[u] = timer++;
  // Guardo la posicion en la cual aparece su valor
  pos_in[a[u]].push_back(in[u]);
  for (int v : adj[u]) if (v != p) DFS(v, u);
  // En el cual he terminado de visitar a todos los descendientes del nodo
  out[u] = timer++;
}

bool HasValue(int val, int l, int r) {
  if (l > r) return false;
  int cnt = upper_bound(pos_in[val].begin(), pos_in[val].end(), r) - lower_bound(pos_in[val].begin(), pos_in[val].end(), l);
  return (cnt > 0);
}

void Solve(void) {
  // Leo la entrada
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // Comprimo los valores para poder guardar informacion de las posiciones de los valores en un rango
  CoordinateCompression(n);
  // Aplano el grafo con un Euler Tour
  DFS(0);
  // Para cada nodo, si tendo dos nodos con el mismo valor en distintos subtrees,
  // entonces es imposible obtener alguna raiz distintiva y la respuesta es cero
  vector<int> add(2 * n + 1, 0);
  for (int u = 0; u < n; u++) {
    int cnt = 0;
    int last = -1;
    for (int v : adj[u]) {
      // Si es mi padre, analizo el complemento de mi subarbol
      if (v == parent[u]) {
        if (HasValue(a[u], 0, in[u] - 1) || HasValue(a[u], out[u] + 1, 2 * n - 1)) {
          last = v;
          cnt++;
        }
      } else {
        if (HasValue(a[u], in[v], out[v])) {
          last = v;
          cnt++;
        }
      }
    }
    if (cnt == 1) {
      if (last == parent[u]) {
        add[in[u]]++;
        add[out[u] + 1]--;
      } else {
        if (in[last] > 0) {
          add[0]++;
          add[in[last]]--;
        }
        if (out[last] < 2 * n - 1) {
          add[out[last] + 1]++;
          add[2 * n]--;
        }
      }
    } else if (cnt > 1) {
      cout << 0 << '\n';
      return;
    }
  }
  vector<int> acc(2 * n, 0);
  int cur = 0;
  for (int i = 0; i < 2 * n; i++) {
    cur += add[i];
    acc[i] = cur;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) if (acc[in[i]] == 0) ans++;
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;
const Long MOD = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct DisjointSets {
  int parent[N];
  int size[N];

  void MakeSet(int u) {
    parent[u] = u;
    size[u] = 1;
  }

  void Build(int n) {
    for (int i = 0; i < n; i++) MakeSet(i);
  }

  int Find(int u) {
    if (parent[u] == u) {
      return u;
    } else {
      return (parent[u] = Find(parent[u]));
    }
  }

  void Join(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u != v) {
      if (size[u] > size[v]) swap(u, v);
      parent[u] = v;
      size[v] += size[u];
    }
  }

  bool SameSet(int u, int v) {
    return (Find(u) == Find(v));
  }

  int GetSize(int u) {
    return size[Find(u)];
  }
};

void Solve(void) {
  Long n, m;
  cin >> n >> m;
  DisjointSets dsu;
  dsu.Build(m + 1);
  Long cnt = 1;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    int u;
    cin >> u;
    int v = 0;
    if (k == 2) cin >> v;
    if (!dsu.SameSet(u, v)) {
      dsu.Join(u, v);
      cnt = (cnt * 2LL) % MOD;
      ans.push_back(i + 1);
    }
  }
  int len = ans.size();
  cout << cnt << " " << len << '\n';
  for (int i = 0; i < len; i++) cout << ans[i] << " ";
  cout << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


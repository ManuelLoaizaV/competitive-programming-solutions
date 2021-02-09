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

const int N = 1e5;
const Long MOD = 1e9 + 7;

vector<int> adj[N];
int in[N], out[N], timer;

void AddEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void DFS(int u, int p) {
  in[u] = ++timer;
  for (int v : adj[u]) if (v != p) DFS(v, u);
  out[u] = timer;
}

Long Add(Long a, Long b) {
  return (a + b) % MOD;
}

Long Mul(Long a, Long b) {
  return (a * b) % MOD;
}

struct SegmentTree {
  Pair tree[4 * N];
  int n;
  Pair Merge(const Pair& a, const Pair& b) {
    return {Add(a.first, b.first), Mul(a.second, b.second)};
  }
  void Build(int id, int tl, int tr) {
    if (tl == tr) {
      tree[id] = {0, 1LL};
    } else {
      int tm = (tl + tr) / 2;
      Build(2 * id, tl, tm);
      Build(2 * id + 1, tm + 1, tr);
      tree[id] = Merge(tree[2 * id], tree[2 * id + 1]);
    }
  }
  void Update(int pos, Pair val, int id, int tl, int tr) {
    if (tl == tr) {
      tree[id] = Merge(tree[id], val);
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        Update(pos, val, 2 * id, tl, tm);
      } else {
        Update(pos, val, 2 * id + 1, tm + 1, tr);
      }
      tree[id] = Merge(tree[2 * id], tree[2 * id + 1]);
    }
  }
  Pair Query(int l, int r, int id, int tl, int tr) {
    if (l <= tl && tr <= r) return tree[id];
    int tm = (tl + tr) / 2;
    if (r <= tm) return Query(l, r, 2 * id, tl, tm);
    if (tm < l) return Query(l, r, 2 * id + 1, tm + 1, tr);
    return Merge(Query(l, r, 2 * id, tl, tm), Query(l, r, 2 * id + 1, tm + 1, tr));
  }
  void Update(int pos, Pair val) { Update(pos, val, 1, 0, n - 1); }
  Pair Query(int l, int r) { return Query(l, r, 1, 0, n - 1); }
} st[6];

Long primes[6] = {2, 3, 5, 7, 11, 13};

void Seed(int pos, Long x) {
  for (int i = 0; i < 6; i++) {
    Long p = primes[i];
    Long cnt = 0;
    Long pot = 1LL;
    while (x % p == 0) {
      cnt++;
      x /= p;
      pot = Mul(pot, p);
    }
    st[i].Update(pos, {cnt, pot});
  }
}

void Solve(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    AddEdge(u, v);
  }
  // Aplano el arbol
  timer = -1;
  DFS(0, -1);
  // Construyo el segment tree
  for (int i = 0; i < 6; i++) {
    st[i].n = n;
    st[i].Build(1, 0, timer);
  }
  for (int i = 0; i < n; i++) {
    Long x;
    cin >> x;
    Seed(in[i], x);
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    if (s[0] == 'R') {
      Long u;
      cin >> u;
      Long product, divisors;
      product = 1LL;
      divisors = 1LL;
      for (int i = 0; i < 6; i++) {
        Pair current = st[i].Query(in[u], out[u]);
        product = Mul(product, current.second);
        divisors = Mul(divisors, (current.first + 1) % MOD);
        //debug(current, product, divisors);
      }
      cout << product << " " << divisors << '\n';
    } else {
      Long u, x;
      cin >> u >> x;
      Seed(in[u], x);
    }
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


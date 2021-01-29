//https://codeforces.com/contest/1478/problem/E
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
typedef pair<int, int> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SegmentTree {
  Pair tree[4 * N];
  // lazy[id] = {
  // 0: Cambiar todo a 0
  // 1: Cambiar todo a 1
  // 2: Nada pendiente
  // }
  int lazy[4 * N];

  Pair Merge(const Pair& a, const Pair& b) {
    return {a.first + b.first, a.second + b.second};
  }

  void Build(const string& s, int id, int tl, int tr) {
    lazy[id] = 2;
    if (tl == tr) {
      tree[id].first = tree[id].second = 0;
      if (s[tl] == '0') {
        tree[id].first = 1;
      } else {
        tree[id].second = 1;
      }
    } else {
      int tm = (tl + tr) / 2;
      Build(s, 2 * id, tl, tm);
      Build(s, 2 * id + 1, tm + 1, tr);
      tree[id] = Merge(tree[2 * id], tree[2 * id + 1]);
    }
  }

  void Push(int id, int tl, int tr) {
    if (lazy[id] < 2) {
      int left = 2 * id;
      int right = 2 * id + 1;
      int tm = (tl + tr) / 2;
      // Aplicar
      if (lazy[id] == 0) {
        tree[left].first = tm - tl + 1;
        tree[left].second = 0;
        tree[right].first = tr - tm;
        tree[right].second = 0;
      } else {
        tree[left].first = 0;
        tree[left].second = tm - tl + 1;
        tree[right].first = 0;
        tree[right].second = tr - tm;
      }
      // Acumular
      lazy[left] = lazy[right] = lazy[id];
      // Reiniciar
      lazy[id] = 2;
    }
  }

  void Update(int l, int r, int nxt, int id, int tl, int tr) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
      // Aplicar
      int distance = tr - tl + 1;
      if (nxt == 0) {
        tree[id].first = distance;
        tree[id].second = 0;
      } else {
        tree[id].first = 0;
        tree[id].second = distance;
      }
      // Acumular
      lazy[id] = nxt;
    } else {
      int tm = (tl + tr) / 2;
      Push(id, tl, tr);
      Update(l, r, nxt, 2 * id, tl, tm);
      Update(l, r, nxt, 2 * id + 1, tm + 1, tr);
      tree[id] = Merge(tree[2 * id], tree[2 * id + 1]);
    }
  }

  Pair Query(int l, int r, int id, int tl, int tr) {
    if (l <= tl && tr <= r) return tree[id];
    int tm = (tl + tr) / 2;
    Push(id, tl, tr);
    if (r <= tm) return Query(l, r, 2 * id, tl, tm);
    if (tm < l) return Query(l, r, 2 * id + 1, tm + 1, tr);
    return Merge(Query(l, r, 2 * id, tl, tm), Query(l, r, 2 * id + 1, tm + 1, tr));
  }
} st;

void Solve(void) {
  Long n, q;
  cin >> n >> q;
  string s, t;
  cin >> s >> t;
  vector<pair<int, int>> queries;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries.push_back({l - 1, r - 1});
  }
  reverse(queries.begin(), queries.end());
  st.Build(t, 1, 0, n - 1);
  for (int i = 0; i < q; i++) {
    Pair range = st.Query(queries[i].first, queries[i].second, 1, 0, n - 1);
    //debug(queries[i], range);
    int zeros = range.first;
    int ones = range.second;
    if (zeros == ones) {
      cout << "NO" << '\n';
      return;
    }
    if (zeros == 0 || ones == 0) continue;
    st.Update(queries[i].first, queries[i].second, (zeros < ones) ? 1 : 0, 1, 0, n - 1);
  }
  for (int i = 0; i < n; i++) {
    Pair current = st.Query(i, i, 1, 0, n - 1);
    //debug(current);
    if (current.first == 1 && s[i] == '0') continue;
    if (current.second == 1 && s[i] == '1') continue;
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

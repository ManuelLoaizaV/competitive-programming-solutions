// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (Long i = a; i < b; i++)
#define roF(i,a,b) for (Long i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

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
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 1e5 + 5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct LinkCut {
  struct Node {
    int p = 0, c[2] = {0, 0}, pp = 0;
    bool flip = 0;
    int val = 0, dp = 0;
  };
  vector<Node> T;
 
  LinkCut(int n) : T(n + 1) {}
 
  // SPLAY TREE OPERATIONS START

  int dir(int x, int y) { return T[x].c[1] == y; }
 
  void set(int x, int d, int y) {
    if (x) T[x].c[d] = y, pull(x);
    if (y) T[y].p = x;
  }
 
  void pull(int x) {
    if (!x) return;
    int &l = T[x].c[0], &r = T[x].c[1];
    T[x].dp = max({T[x].val, T[l].dp, T[r].dp});
  }
 
  void push(int x) {
    if (!x || !T[x].flip) return;
    int &l = T[x].c[0], &r = T[x].c[1];
    swap(l, r); T[l].flip ^= 1; T[r].flip ^= 1;
    T[x].flip = 0;
  }
 
  void rotate(int x, int d) { 
    int y = T[x].p, z = T[y].p, w = T[x].c[d];
    swap(T[x].pp, T[y].pp);
    set(y, !d, w);
    set(x, d, y);
    set(z, dir(z, y), x);
  }
 
  void splay(int x) { 
    for (push(x); T[x].p;) {
      int y = T[x].p, z = T[y].p;
      push(z); push(y); push(x);
      int dx = dir(y, x), dy = dir(z, y);
      if (!z) 
        rotate(x, !dx); 
      else if (dx == dy) 
        rotate(y, !dx), rotate(x, !dx); 
      else
        rotate(x, dy), rotate(x, dx);
    }
  }
 
  // SPLAY TREE OPERATIONS END
 
  void MakeRoot(int u) {
    Access(u);
    int l = T[u].c[0];
    T[l].flip ^= 1;
    swap(T[l].p, T[l].pp);
    set(u, 0, 0);
  }
 
  void Access(int _u) {
    for (int v = 0, u = _u; u; u = T[v = u].pp) {
      splay(u); splay(v);
      int r = T[u].c[1];
      T[v].pp = 0;
      swap(T[r].p, T[r].pp);
      set(u, 1, v);
    }
    splay(_u);
  }

  void Link(int u, int v) { 
    assert(!Connected(u, v));
    MakeRoot(v);
    T[v].pp = u;
  }

  void Cut(int u, int v) {
    MakeRoot(u); Access(u); splay(v);
    assert(T[v].pp == u);
    T[v].pp = 0;
  }

  bool Connected(int u, int v) {
    if (u == v) return true;
    MakeRoot(u); Access(v); splay(u);
    return T[v].p == u || T[T[v].p].p == u;
  }

  int GetPath(int u, int v) {
    MakeRoot(u); Access(v); return v;
  }
};

void solve() {
    int n;
    cin >> n;
    LinkCut lct(n);
    char c;
    while (cin >> c) {
        if (c == 'E') break;
        int u, v;
        cin >> u >> v;
        if (c == 'C') {
            lct.Link(u, v);
        }
        if (c == 'D') {
            lct.Cut(u, v);
        }
        if (c == 'T') {
            if (lct.Connected(u, v)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
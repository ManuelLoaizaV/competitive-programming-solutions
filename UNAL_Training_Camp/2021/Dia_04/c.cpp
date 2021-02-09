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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct Punto {
  Long x, y, z;
  Punto(void) {}
  Punto(Long _x, Long _y, Long _z) {
    x = _x;
    y = _y;
    z = _z;
  }
  void Read(void) {
    cin >> x >> y >> z;
  }
  Punto operator + (Punto p) { return Punto(x + p.x, y + p.y, z + p.z); }
  Punto operator - (Punto p) { return Punto(x - p.x, y - p.y, z - p.z); }
  bool operator == (Punto p) { return x == p.x && y == p.y && z == p.z; }
};

Punto Cross(const Punto& p1, const Punto& p2) {
  return Punto(p1.y * p2.z - p1.z * p2.y, p1.z * p2.x - p1.x * p2.z, p1.x * p2.y - p1.y * p2.x);
}

const Punto ZERO = {0, 0, 0};

void Solve(void) {
  Long n;
  cin >> n;
  vector<Punto> p(n);
  for (int i = 0; i < n; i++) {
    p[i].Read();
    if (i > 0) p[i] = p[i] - p[0];
  }
  Long ans = 0;
  vector<bool> is_done(n, false);
  is_done[0] = true;
  for (int i = 1; i < n; i++) {
    if (!is_done[i]) {
      for (int j = 1; j < n; j++) if (Cross(p[i], p[j]) == ZERO) is_done[j] = true;
      ans++;
    }
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


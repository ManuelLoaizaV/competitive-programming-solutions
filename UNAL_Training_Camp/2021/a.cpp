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
const Long INF = LLONG_MAX;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct Punto {
  Long x, y;
  void Read(void) {
    cin >> x >> y;
  }
  Punto operator - (const Punto& other) const {
    return Punto{x - other.x, y - other.y};
  }
  void operator -= (const Punto& other) {
    x -= other.x;
    y -= other.y;
  }
  Long operator * (const Punto& other) const {
    return x * other.y - y * other.x;
  }
  bool operator < (const Punto& other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
  Long Triangle(const Punto& p2, const Punto& p3) const {
    return (p2 - *this) * (p3 - *this);
  }
};

Long Distance2(const Punto& p1, const Punto& p2) {
  Long dx = p1.x - p2.x;
  Long dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<Punto> points(n);
  for (int i = 0; i < n; i++) points[i].Read();
  vector<bool> is_used(n, false);
  vector<int> ans;
  ans.push_back(0);
  is_used[0] = true;
  for (int i = 0; i < n - 1; i++) {
    Long mx = 0LL;
    Punto last = points[ans.end()[-1]];
    int candidate = -1;
    for (int j = 0; j < n; j++) {
      if (!is_used[j]) {
        Long current = Distance2(last, points[j]);
        if (current > mx) {
          mx = current;
          candidate = j;
        }
      }
    }
    ans.push_back(candidate);
    is_used[candidate] = true;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << '\n';
}


int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


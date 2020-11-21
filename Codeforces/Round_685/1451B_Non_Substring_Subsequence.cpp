//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(nullptr)
using namespace std;
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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void Solve(void) {
  Long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int l[n][2], r[n][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      l[i][j] = r[i][j] = 0;
    }
  }
  l[0][s[0] - '0'] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      l[i][j] = l[i - 1][j];
    }
    l[i][s[i] - '0']++;
  }
  r[n - 1][s[n - 1] - '0'] = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      r[i][j] = r[i + 1][j];
    }
    r[i][s[i] - '0']++;
  }
  while (q--) {
    Long _l, _r;
    cin >> _l >> _r;
    _l--;
    _r--;
    if (_l == 0 && _r == n- 1) {
      cout << "NO" << '\n';
      continue;
    }
    if (_l == 0) {
      if (r[_r + 1][s[_r] - '0'] == 0) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
      }
      continue;
    }
    if (_r == n - 1) {
      if (l[_l - 1][s[_l] - '0'] == 0) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
      }
      continue;
    }
    if (r[_r + 1][s[_r] - '0'] == 0 && l[_l - 1][s[_l] - '0'] == 0) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

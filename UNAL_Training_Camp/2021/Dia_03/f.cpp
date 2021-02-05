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

void Solve(void) {
  Long n;
  cin >> n;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  /*
  vector<bool> increasing(n, false), decreasing(n, false);
  increasing[0] = true;
  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) {
      increasing[i] = true;
    } else {
      break;
    }
  }
  decreasing[n - 1] = true;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] >= a[i + 1]) {
      decreasing[i] = true;
    } else {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (increasing[i] && decreasing[i]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  */
  for (int i = 0; i < n; i++) {
    bool is_unimodal = true;
    // El actual es la moda
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] >= a[j + 1]) {
        is_unimodal = false;
        break;
      }
    }
    if (!is_unimodal) continue;
    int last;
    for (int j = i; j < n; j++) {
      if (a[j] == a[i]) {
        last = j;
      } else {
        break;
      }
    }
    for (int j = last + 1; j < n; j++) {
      if (a[j] >= a[j - 1]) {
        is_unimodal = false;
        break;
      }
    }
    if (!is_unimodal) continue;
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


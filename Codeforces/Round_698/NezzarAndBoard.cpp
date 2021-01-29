//https://codeforces.com/contest/1478/problem/D
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
  Long n, k;
  cin >> n >> k;
  vector<Long> x(n);
  set<Long> uni;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    uni.insert(x[i]);
  }
  sort(x.begin(), x.end());
  if (uni.count(k) > 0) {
    cout << "YES" << '\n';
    return;
  }
  set<Long> distances;
  distances.insert(x[1] - x[0]);
  for (int i = 2; i < n; i++) {
    distances.insert(x[i] - x[i - 1]);
  }
  bool first_time = true;
  Long gcd;
  for (auto x : distances) {
    //debug(x);
    if (first_time) {
      gcd = x;
      first_time = false;
    } else {
      gcd = __gcd(gcd, x);
    }
  }
  Long distance = abs(k - x[0]);
  //debug(distance, gcd);
  if (distance % gcd == 0) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}


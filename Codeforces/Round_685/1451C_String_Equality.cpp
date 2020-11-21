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

const int N = 26;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void Solve(void) {
  int n, k;
  cin >> n >> k;
  string  a, b;
  cin >> a >> b;
  if (a == b) {
    cout << "Yes" << '\n';
    return;
  }
  vector<int> cnt_a(N, 0);
  vector<int> cnt_b(N, 0);
  for (char c : a) cnt_a[c - 'a']++;
  for (char c : b) cnt_b[c - 'a']++;

  if (cnt_a[0] < cnt_b[0]) {
    cout << "No" << '\n';
    return;
  }
  cnt_a[0] -= cnt_b[0];
  if (cnt_a[0] % k != 0) {
    cout << "No" << '\n';
    return;
  }
  int prev = cnt_a[0];
  for (int i = 1; i < N - 1; i++) {
    cnt_a[i] += prev;
    if (cnt_a[i] < cnt_b[i]) {
      cout << "No" << '\n';
      return;
    }
    cnt_a[i] -= cnt_b[i];
    if (cnt_a[i] % k != 0) {
      cout << "No" << '\n';
      return;
    }
    prev = cnt_a[i];
  }
  if (prev + cnt_a[N - 1] == cnt_b[N - 1]) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

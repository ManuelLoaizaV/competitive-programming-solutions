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

const int N = 5e3;
const Long INF = 1e18;
const Double EPS = 1e-9;
const Long MOD = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long n, k, q;
Long dp[N + 2][N + 2];
bool is_done[N + 2][N + 2];

Long Sum(Long a, Long b) {
  return (a + b) % MOD;
}

Long Sub(Long a, Long b) {
  return (a - b + MOD) % MOD;
}

Long Mul(Long a, Long b) {
  return (a * b) % MOD;
}

// DP(c, pos): # good paths that have color c in position pos - 1
Long DP(Long c, Long pos) {
  if (pos == k) return 1LL;
  if (is_done[c][pos]) return dp[c][pos];
  dp[c][pos] = 0LL;
  is_done[c][pos] = true;
  if (c > 0) dp[c][pos] = Sum(dp[c][pos], DP(c - 1, pos + 1));
  if (c < n - 1) dp[c][pos] = Sum(dp[c][pos], DP(c + 1, pos + 1));
  return dp[c][pos];
}

void Solve(void) {
  cin >> n >> k >> q;
  k++;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<Long> cnt(n, 0);
  for (Long pos = 0; pos < k; pos++) {
    Long len_1 = pos + 1;
    Long len_2 = k - pos;
    for (Long color = 0; color < n; color++) {
      cnt[color] = Sum(cnt[color], Mul(DP(color, k - len_1 + 1), DP(color, k - len_2 + 1)));
    }
  }
  Long sum = 0LL;
  for (int i = 0; i < n; i++) sum = Sum(sum, Mul(a[i], cnt[i]));
  while (q--) {
    Long i, x;
    cin >> i >> x;
    i--;
    sum = Sub(sum, Mul(a[i], cnt[i]));
    a[i] = x;
    sum = Sum(sum, Mul(a[i], cnt[i]));
    cout << sum << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


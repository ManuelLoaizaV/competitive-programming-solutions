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
const Long MOD = 1e9 + 7;
const Long LG = 60;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long pot[LG + 1];
Long cnt[LG];

Long Add(Long a, Long b) {
  return (a + b) % MOD;
}

Long Mul(Long a, Long b) {
  return (a * b) % MOD;
}

void Precalculate(void) {
  pot[0] = 1LL;
  for (Long i = 1; i <= LG; i++) pot[i] = Mul(pot[i - 1], 2LL);
}

void Initialize(void) {
  for (Long i = 0; i < LG; i++) cnt[i] = 0LL;
}

void Count(Long n) {
  for (Long i = 0; i < LG; i++) {
    if (n & 1) cnt[i]++;
    n >>= 1;
  }
}

Long Or(Long n, Long len) {
  Long ans = 0;
  for (Long i = 0; i < LG; i++) {
    if (n & 1) {
      ans = Add(ans, Mul(len, pot[i]));
    } else {
      ans = Add(ans, Mul(cnt[i], pot[i]));
    }
    n >>= 1;
  }
  return ans;
}

Long And(Long n, Long len) {
  Long ans = 0;
  for (Long i = 0; i < LG; i++) {
    if (n & 1) ans = Add(ans, Mul(cnt[i], pot[i]));
    n >>= 1;
  }
  return ans;
}

void Solve(void) {
  Initialize();
  Long n;
  cin >> n;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    Count(a[i]);
  }
  Long ans = 0LL;
  for (int i = 0; i < n; i++) {
    Long or_sum = Or(a[i], n);
    Long and_sum = And(a[i], n);
    ans = Add(ans, Mul(or_sum, and_sum));
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  Precalculate();
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}


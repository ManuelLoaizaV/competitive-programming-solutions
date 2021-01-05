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

Long fact[N + 1];

void Sieve(void) {
  for (int i = 0; i <= N; i++) fact[i] = i;
  for (int i = 2; i * i <= N; i++) {
    if (fact[i] == i) {
      for (int j = i * i; j <= N; j += i) {
        fact[j] = i;
      }
    }
  }
}

Long Factorize(Long n) {
  Long ans = 1;
  while (n > 1) {
    Long cnt = 0;
    Long p = fact[n];
    while (n % p == 0) {
      n /= p;
      cnt++;
    }
    if (cnt & 1) ans *= p;
  }
  return ans;
}

void Solve(void) {
  Long n;
  cin >> n;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<Long, Long> cnt;
  for (int i = 0; i < n; i++) cnt[Factorize(a[i])]++;
  Long mx = 0;
  Long even = 0;
  Long odd = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    Long cur = it->second;
    if ((it->first) == 1 || cur % 2 == 0) {
      even += cur;
    } else {
      odd = max(odd, cur);
    }
    mx = max(mx, cur);
  }
  Long q;
  cin >> q;
  while (q--) {
    Long w;
    cin >> w;
    if (w == 0) {
      cout << mx << '\n';
    } else {
      cout << max(even, odd) << '\n';
    }
  }
}

int main(void) {
  FAST_IO;
  Sieve();
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}

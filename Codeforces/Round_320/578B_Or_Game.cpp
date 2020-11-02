// Gracias, Rodolfo
// Gracias, Graphter
// Gracias, Osman
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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void solve() {
  Long n, k, x;
  cin >> n >> k >> x;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<Long> left(n + 2);
  vector<Long> right(n + 2);
  left[0] = 0;
  for (int i = 1; i <= n; i++) left[i] = left[i - 1] | a[i - 1];
  right[n + 1] = 0;
  for (int i = n; i > 0; i--) right[i] = right[i + 1] | a[i - 1];
  left[n + 1] = left[n];
  right[0] = right[1];
  Long ans = right[0];
  Long mul = 1LL;
  for (int i = 0; i < k; i++) mul *= x;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, left[i - 1] | (a[i - 1] * mul) | right[i + 1]);
  }
  cout << ans << '\n';
}

int main() {
  fastio;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}

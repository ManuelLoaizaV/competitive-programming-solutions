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

const int N = 1e3 + 5;
const Long INF = 1e18;
const Double EPS = 1e-9;
const Long MOD = 1e9 + 7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long nck[N][N];
bool a[N][N], is_done[N][N];

Long nCk(int n, int k) {
  if (k == 0 || n == k) return 1LL;
  if (is_done[n][k]) return nck[n][k];
  nck[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k)) % MOD;
  is_done[n][k] = true;
  return nck[n][k];
}

void Solve(void) {
  Long n, k;
  cin >> n >> k;
  vector<Long> cnt(n);
  for (int i = 0; i < n; i++) cin >> cnt[i];
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  Long who = cnt[k - 1];
  Long choose = 0;
  for (int i = 0; i < n; i++) if (cnt[i] == who) choose++;
  Long choosen = 0;
  for (int i = 0; i < k; i++) if (cnt[i] > who) choosen++;
  Long remaining = k - choosen;
  cout << nCk(choose, remaining) << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}


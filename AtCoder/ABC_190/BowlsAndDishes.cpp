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

int GetBit(int mask, int bit) { return (mask >> bit) & 1; }
void TurnOn(int& mask, int bit) { mask = mask | (1 << bit); }
void TurnOff(int& mask, int bit) { mask = mask & (~(1 << bit)); }

void Solve(void) {
  int n, m;
  cin >> n >> m;
  vector<Pair> condition(m);
  for (int i = 0; i < m; i++) cin >> condition[i].first >> condition[i].second;
  int k;
  cin >> k;
  vector<vector<int>> people(k, vector<int>(2, 0));
  for (int i = 0; i < k; i++)
    for (int j = 0; j < 2; j++)
      cin >> people[i][j];
  vector<int> cnt(n + 1);
  int ans = 0;
  int limit = 1 << k;
  for (int mask = 0; mask < limit; mask++) {
    for (int i = 0; i <= n; i++) cnt[i] = 0;
    for (int bit = 0; bit < k; bit++) cnt[people[bit][GetBit(mask, bit)]]++;
    int tmp = 0;
    for (int i = 0; i < m; i++) if (cnt[condition[i].first] > 0 && cnt[condition[i].second] > 0) tmp++;
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}


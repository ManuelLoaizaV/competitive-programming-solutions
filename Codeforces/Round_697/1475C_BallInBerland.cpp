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
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void Solve(void) {
  Long a, b, k;
  cin >> a >> b >> k;
  vector<Pair> pairs(k);
  vector<vector<Long>> positions_a(a + 1);
  vector<vector<Long>> positions_b(b + 1);
  for (Long i = 0; i < k; i++) {
    cin >> pairs[i].first;
    positions_a[pairs[i].first].push_back(i);
  }
  for (Long i = 0; i < k; i++) {
    cin >> pairs[i].second;
    positions_b[pairs[i].second].push_back(i);
  }
  Long ans = k * (k - 1) / 2;
  Long arriba, abajo;
  arriba = abajo = 0LL;
  for (Long i = 0; i <= a; i++) {
    Long current = positions_a[i].size();
    Long current_pairs = current * (current - 1) / 2;
    ans -= current_pairs;
  }
  for (Long i = 0; i <= b; i++) {
    Long current = positions_b[i].size();
    Long current_pairs = current * (current - 1) / 2;
    ans -= current_pairs;
  }
  map<Pair, Long> cnt;
  for (Long i = 0; i < k; i++) {
    cnt[pairs[i]]++;
  }
  for (auto current_pair : cnt) {
    Long current = current_pair.second;
    Long current_pairs = current * (current - 1) / 2;
    ans += current_pairs;
  }
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}


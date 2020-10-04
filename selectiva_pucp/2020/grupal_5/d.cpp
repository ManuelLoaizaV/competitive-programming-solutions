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
const int INF = 1e9;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

int Count(vector<int> a, vector<int>& b, int ini) {
  vector<int> c;
  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < b[i]; j++) c.push_back(ini);
    ini = 1 - ini;
  }
  int acc[2][2];
  memset(acc, 0, sizeof(acc));
  int n = a.size();
  for (int i = 0; i < n; i++) {
    acc[0][a[i]]++;
    acc[1][c[i]]++;
  }
  bool ok = true;
  for (int i = 0; i < 2; i++) {
    if (acc[0][i] != acc[1][i]) ok = false;
  }
  if (!ok) return INF;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == c[i]) continue;
    for (int j = i + 1; j < n; j++) {
      if (a[j] == c[i]) {
        while (j != i) {
          swap(a[j - 1], a[j]);
          cnt++;
          j--;
        }
        break;
      }
    }
  }
  return cnt;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  vector<int> b;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  int ans = min(Count(a, b, 0), Count(a, b, 1));
  cout << ans << '\n';
}

int main() {
  fastio;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}

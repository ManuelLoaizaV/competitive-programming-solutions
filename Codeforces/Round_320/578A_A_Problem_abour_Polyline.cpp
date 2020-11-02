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

Double Search(Long cota, Long num) {
  if (num <= 0) return 0.0;
  if (num / 2.0 < cota) return (Double) INF;
  Long left = 1;
  Long right = 2e9;
  while (right - left > 1) {
    Long mid = (left + right) / 2;
    Double div = (Double) num / (2 * mid);
    //debug(mid, div);
    if (div >= cota) left = mid;
    else right = mid;
  }
  Double result = (Double) num / (2 * left);
  return result;
}

void solve() {
  Long a, b;
  cin >> a >> b;
  Long suma = a + b;
  Long resta = a - b;
  if (resta == 0) {
    cout << a << '\n';
    return;
  }
  if (resta < 0) {
    cout << -1 << '\n';
    return;
  }
  Double minimo_creciente = Search(b, resta);
  Double minimo_decreciente = Search(b, suma);
  //debug(minimo_creciente, minimo_decreciente);
  Double answer = min(minimo_creciente, minimo_decreciente);
  if (answer == (Double) INF) {
    cout << -1 << '\n';
    return;
  }
  cout << fixed << setprecision(10) << answer << '\n';
}

int main() {
  fastio;
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}

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

const int N = 105;
const int ALPH = 26;
const int INF = 1e3;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

string s, t, virus;
int n, m, p;

int pi[N];  // pi sobre el virus
int aut[N][ALPH];  // automata sobre el virus
int dp[N][N][N];
bool is_done[N][N][N];

int DP(int i, int j, int k) {
  if (k == p) return -INF;
  if (i == n) return 0;
  if (j == m) return 0;
  if (is_done[i][j][k]) return dp[i][j][k];
  dp[i][j][k] = max(DP(i + 1, j, k), DP(i, j + 1, k));
  if (s[i] == t[j]) dp[i][j][k] = max(dp[i][j][k], 1 + DP(i + 1, j + 1, aut[k][s[i] - 'A']));
  is_done[i][j][k] = true;
  return dp[i][j][k];
}

void Reconstruct(int i, int j, int k) {
  if (i == n) return;
  if (j == m) return;
  if (DP(i, j, k) == DP(i + 1, j, k)) {
    Reconstruct(i + 1, j, k);
    return;
  }
  if (DP(i, j, k) == DP(i, j + 1, k)) {
    Reconstruct(i, j + 1, k);
    return;
  }
  cout << s[i];
  Reconstruct(i + 1, j + 1, aut[k][s[i] - 'A']);
}

void Solve(void) {
  cin >> s >> t >> virus;
  n = s.size();
  m = t.size();
  p = virus.size();

  pi[0] = 0;
  for (int i = 1; i < p; i++) {
    int j = pi[i - 1];
    while (j > 0 && virus[i] != virus[j]) j = pi[j - 1];
    if (virus[i] == virus[j]) j++;
    pi[i] = j;
  }

  for (int chr = 0; chr < ALPH; chr++) aut[0][chr] = 0;  // Casos base
  aut[0][virus[0] - 'A'] = 1;  // Solo el primer caracter permite avanzar
  for (int i = 1; i <= n; i++) {
    for (int chr = 0; chr < ALPH; chr++) {
      if (i < n && chr == (virus[i] - 'A')) {
        aut[i][chr] = i + 1;
      } else {
        aut[i][chr] = aut[pi[i - 1]][chr];
      }
    }
  }

  if (DP(0, 0, 0) <= 0) {
    cout << 0 << '\n';
  } else {
    Reconstruct(0, 0, 0);
    cout << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}

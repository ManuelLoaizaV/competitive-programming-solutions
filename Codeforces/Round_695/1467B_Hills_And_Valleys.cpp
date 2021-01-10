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

bool IsHill(const vector<Long>& a, int i) {
  int n = a.size();
  if (0 < i && i < n - 1) return a[i] > a[i + 1] && a[i] > a[i - 1];
  return false;
}

bool IsValley(const vector<Long>& a, int i) {
  int n = a.size();
  if (0 < i && i < n - 1) return a[i] < a[i + 1] && a[i] < a[i - 1];
  return false;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<Long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  Long ans = 0;
  for (int i = 1; i < n; i++) {
    if (IsHill(a, i)) ans++;
    if (IsValley(a, i)) ans++;
  }
  vector<Long> acc_l(n, 0);
  vector<Long> acc_r(n, 0);
  for (int i = 1; i < n; i++) {
    acc_l[i] = acc_l[i - 1];
    if (IsHill(a, i)) acc_l[i]++;
    if (IsValley(a, i)) acc_l[i]++;
  }
  for (int i = n - 2; i >= 0; i--) {
    acc_r[i] = acc_r[i + 1];
    if (IsHill(a, i)) acc_r[i]++;
    if (IsValley(a, i)) acc_r[i]++;
  }
  Long cur;
  // Inicio
  cur = (n >= 3) ? acc_r[2] : 0;
  Long init = a[0];
  a[0] = a[1] - 1;
  Long tmp = cur + IsHill(a, 1) + IsValley(a, 1);
  ans = min(ans, tmp);
  
  a[0] = a[1];
  tmp = cur + IsHill(a, 1) + IsValley(a, 1);
  ans = min(ans, tmp);
  
  a[0] = a[1] + 1;
  tmp = cur + IsHill(a, 1) + IsValley(a, 1);
  ans = min(ans, tmp);
  a[0] = init;

  // Medio
  for (int i = 1; i < n - 1; i++) {
    cur = (i >= 2) ? acc_l[i - 2] : 0;
    cur += (i <= n - 3) ? acc_r[i + 2] : 0;
    init = a[i];
    
    a[i] = a[i - 1] - 1;
    tmp = cur + IsHill(a, i - 1) + IsValley(a, i - 1) + IsHill(a, i) + IsValley(a, i) + IsHill(a, i + 1) + IsValley(a, i + 1);
    ans = min(ans, tmp);
    
    a[i] = a[i - 1];
    tmp = cur + IsHill(a, i - 1) + IsValley(a, i - 1) + IsHill(a, i) + IsValley(a, i) + IsHill(a, i + 1) + IsValley(a, i + 1);
    ans = min(ans, tmp);
    
    a[i] = a[i - 1] + 1;
    tmp = cur + IsHill(a, i - 1) + IsValley(a, i - 1) + IsHill(a, i) + IsValley(a, i) + IsHill(a, i + 1) + IsValley(a, i + 1);
    ans = min(ans, tmp);

    a[i] = a[i + 1] - 1;
    tmp = cur + IsHill(a, i - 1) + IsValley(a, i - 1) + IsHill(a, i) + IsValley(a, i) + IsHill(a, i + 1) + IsValley(a, i + 1);
    ans = min(ans, tmp);

    a[i] = a[i + 1];
    tmp = cur + IsHill(a, i - 1) + IsValley(a, i - 1) + IsHill(a, i) + IsValley(a, i) + IsHill(a, i + 1) + IsValley(a, i + 1);
    ans = min(ans, tmp);

    a[i] = a[i + 1] + 1;
    tmp = cur + IsHill(a, i - 1) + IsValley(a, i - 1) + IsHill(a, i) + IsValley(a, i) + IsHill(a, i + 1) + IsValley(a, i + 1);
    ans = min(ans, tmp);

    a[i] = init;
  }
  // Fin
  cur = (n >= 3) ? acc_l[n - 3] : 0;
  a[n - 1] = a[n - 2] - 1;
  tmp = cur + IsHill(a, n - 2) + IsValley(a, n - 2);
  ans = min(ans, tmp);
  
  a[n - 1] = a[n - 2];
  tmp = cur + IsHill(a, n - 2) + IsValley(a, n - 2);
  ans = min(ans, tmp);

  a[n - 1] = a[n - 2] + 1;
  tmp = cur + IsHill(a, n - 2) + IsValley(a, n - 2);
  ans = min(ans, tmp);
  cout << ans << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}


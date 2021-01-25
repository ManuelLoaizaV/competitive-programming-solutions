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

void Solve(void) {
  Long n, m;
  cin >> n >> m;
  vector<Long> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  Long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  if (sum < m) {
    cout << -1 << '\n';
    return;
  }
  vector<Long> uno, dos;
  for (int i = 0; i < n; i++) {
    if (b[i] == 1) {
      uno.push_back(a[i]);
    } else {
      dos.push_back(a[i]);
    }
  }
  sort(uno.begin(), uno.end());
  sort(dos.begin(), dos.end());
  Long ans = 0;
  while (m > 0) {
    if (uno.size() == 0) {
      ans += 2LL;
      m -= dos.end()[-1];
      dos.pop_back();
      continue;
    }
    if (dos.size() == 0) {
      ans += 1LL;
      m -= uno.end()[-1];
      uno.pop_back();
      continue;
    }
    if (uno.end()[-1] >= m) {
      ans += 1LL;
      m -= uno.end()[-1];
      uno.pop_back();
      continue;
    }
    if (uno.size() > 1) {
      Long sum = uno.end()[-1] + uno.end()[-2];
      if (sum > dos.end()[-1]) {
        ans += 1LL;
        m -= uno.end()[-1];
        uno.pop_back();
        continue;
      }
    }
    ans += 2LL;
    m -= dos.end()[-1];
    dos.pop_back();
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


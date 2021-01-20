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
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < 2 * n - 1; i++) {
    int sum = a[2 * n - 1] + a[i];
    map<int, int> cnt;
    for (int j = 0; j < 2 * n - 1; j++) {
      if (j != i) cnt[a[j]]++;
    }
    vector<pair<int, int>> ans;
    bool is_ok = true;
    int x = a[2 * n - 1];
    for (int j = 2 * n - 2; j >= 0; j--) {
      if (cnt[a[j]] > 0) {
        int cur = a[j];
        int comp = x - cur;
        if (comp == cur) {
          if (cnt[comp] > 1) {
            ans.push_back({comp, comp});
            cnt[comp] -= 2;
            x = comp;
          } else {
            is_ok = false;
            break;
          }
        } else {
          if (cnt[comp] > 0) {
            ans.push_back({cur, comp});
            cnt[cur]--;
            cnt[comp]--;
            x = max(cur, comp);
          } else {
            is_ok = false;
            break;
          }
        }
      }
    }
    if (is_ok) {
      cout << "YES" << '\n';
      cout << sum << '\n';
      cout << a[i] << " " << a[2 * n - 1] << '\n';
      for (auto p : ans) cout << p.first << " " << p.second << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}


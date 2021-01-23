//https://atcoder.jp/contests/abc189/tasks/abc189_c
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

const int N = 2e4;
const int LG = 17;
const Long INF = 1e9;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SparseTable {
	int st[N][LG + 1];
	// O(nlg(n))
	void build(vector<int> &a, int n) {
		for (int i = 0; i < n; i++) st[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i + (1 << j) <= n; i++)
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	// O(lg(n))
	int query_1(int l, int r) {
		int ans = INF;
		int t = r - l + 1;
		int lg = 32 - (__builtin_clz(t) + 1);
		for (int i = lg; i >= 0; i--) {
			if ((1 << i) <= t) {
				ans = min(ans, st[l][i]);
				l += (1 << i);
				t -= (1 << i);
			}
		}
		return ans;
	}
	// O(1)
	int query_2(int l, int r) {
		int t = r - l + 1;
		int lg = 32 - (__builtin_clz(t) + 1);
		return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
	}
} st;

void Solve(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  st.build(a, n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int mn = st.query_2(i, j);
      ans = max(ans, mn * (j - i + 1));
    }
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


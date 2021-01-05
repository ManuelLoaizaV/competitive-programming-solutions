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

const int N = 3e5;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SegmentTree {
	Long tree[4 * N];	
	void Build(vector<Long> &a, int id, int tl, int tr) {
		if (tl == tr) {
			tree[id] = a[tl];
		} else {
			int tm = (tl + tr) / 2;
			Build(a, 2 * id, tl, tm);
			Build(a, 2 * id + 1, tm + 1, tr);
			tree[id] = min(tree[2 * id], tree[2 * id + 1]);
		}
	}
	void Update(int pos, int val, int id, int tl, int tr) {
		if (tl == tr) {
			tree[pos] = val;
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) Update(pos, val, 2 * id, tl, tm);
			else Update(pos, val, 2 * id + 1, tm + 1, tr);
			tree[id] = min(tree[2 * id], tree[2 * id + 1]);
		}
	}

	Long Query(int l, int r, int id, int tl, int tr) {
		if (l <= tl and tr <= r) return tree[id];
		int tm = (tl + tr) / 2;
		if (r <= tm) return Query(l, r, 2 * id, tl, tm);
		if (tm < l) return Query(l, r, 2 * id + 1, tm + 1, tr);
		return min(Query(l, r, 2 * id, tl, tm), Query(l, r, 2 * id + 1, tm + 1, tr));
	}
} st;

bool comp(const Pair& a, const Pair& b) {
  if (a.first == b.second) return a.second < b.second;
  return a.first > b.first;
}

void Solve(void) {
  Long n, m;
  cin >> n >> m;
  vector<Long> k(n);
  for (int i = 0; i < n; i++) cin >> k[i];
  vector<Long> c(m);
  for (int i = 0; i < m; i++) cin >> c[i];
  Long ans = 0;
  vector<Pair> aux(n);
  for (int i = 0; i < n; i++) {
    aux[i].first = c[k[i] - 1];
    aux[i].second = k[i] - 1;
  }
  sort(aux.begin(), aux.end(), comp);
  //st.Build(c, 1, 0, m - 1);
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (pos < m) {
      if (c[pos] < aux[i].first && pos <= aux[i].second) {
        ans += c[pos];
        pos++;
      } else {
        ans += aux[i].first;
      }
    } else {
      ans += aux[i].first;
    }
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

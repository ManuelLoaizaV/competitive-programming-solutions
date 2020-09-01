// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 5e5;
const Long INF = 1e9 + 1;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct Data {
  Long sum, maxPref, maxSuff, ans;
  Data(){}
  Data(Long x) {
		sum = x;
		maxPref = x;
		maxSuff = x;
		ans = x;
  }
} t[4 * N];

Data combine(Data left, Data right) {
	Data cur;
  cur.sum = left.sum + right.sum;
  cur.maxPref = max(left.maxPref, left.sum + right.maxPref);
  cur.maxSuff = max(right.maxSuff, right.sum + left.maxSuff);
  cur.ans = max(left.ans, max(right.ans, left.maxSuff + right.maxPref));
  return cur;
}

void build(vector<Long> &a, Long id, Long tl, Long tr) {
  if (tl == tr) {
    t[id] = Data(a[tl]);
  } else {
  	int tm = (tl + tr) / 2;
    build(a, 2 * id, tl, tm);
    build(a, 2 * id + 1, tm + 1, tr);
    t[id] = combine(t[2 * id], t[2 * id + 1]);
  }
}

Data query(Long l, Long r, Long id, Long tl, Long tr) {
	if (l <= tl and tr <= r) {
    return t[id];
  }
  Long tm = (tl + tr) / 2;
  if (tm < l) {
    return query(l, r, 2 * id + 1, tm + 1, tr);
  }
  if (r < tm + 1) {
    return query(l, r, 2 * id, tl, tm);
  }
  return combine(query(l, r, 2 * id, tl, tm), query(l, r, 2 * id + 1, tm + 1, tr));
}

void update(Long pos, Long val, Long id, Long tl, Long tr) {
  if (tl == tr) {
    t[id] = Data(val);
  } else {
  	Long tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(pos, val, 2 * id, tl, tm);
    } else {
    	update(pos, val, 2 * id + 1, tm + 1, tr);
    }
    t[id] = combine(t[2 * id], t[2 * id + 1]);
  }
}

void solve() {
	Long n;
	cin >> n;
	pair<char, Long> p[n];
	cin >> p[0].second;
	Long left, right;
	left = right = 0LL;
	For(i, 1, n) {
		cin >> p[i].first >> p[i].second;	
		if (p[i].first == 'L') left++;
	}
	vector<Long> a(n, -INF);
	build(a, 1, 0, n - 1);
	update(left, p[0].second, 1, 0, n - 1);
	cout << query(0, n - 1, 1, 0, n - 1).ans << '\n';
	right = left;
	For(i, 1, n) {
		if (p[i].first == 'L') {
			left--;
			update(left, p[i].second, 1, 0, n - 1);
		} else {
			right++;
			update(right, p[i].second, 1, 0, n - 1);
		}
		cout << query(0, n - 1, 1, 0, n - 1).ans << '\n';
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
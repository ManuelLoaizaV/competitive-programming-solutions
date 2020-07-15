// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
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
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 1e5 + 5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SegmentTree {
	Long lazy[4 * N];
	bool marked[4 * N];
	void build(Long id, Long tl, Long tr) {
		marked[id] = false;
		if (tl == tr) {
			lazy[id] = INF;
		} else {
			Long tm = (tl + tr) / 2;
			build(2 * id, tl, tm);
			build(2 * id + 1, tm + 1, tr);
		}
	}
	void push(Long id) {
		if (marked[id]) {
			Long left = 2 * id;
			Long right = 2 * id + 1;
			lazy[left] = lazy[right] = lazy[id];
			marked[left] = marked[right] = true;
			marked[id] = false;
		}
	}
	void update(Long l, Long r, Long val, Long id, Long tl, Long tr) {
		if (tr < l or tl > r) return;
		if (l <= tl and tr <= r) {
			lazy[id] = val;
			marked[id] = true;
		} else {
			Long tm = (tl + tr) / 2;
			push(id);
			update(l, r, val, 2 * id, tl, tm);
			update(l, r, val, 2 * id + 1, tm + 1, tr);
		}
	}
	Long query(Long pos, Long id, Long tl, Long tr) {
		if (tl == tr) return lazy[id];
		Long tm = (tl + tr) / 2;
		push(id);
		if (pos <= tm) return query(pos, 2 * id, tl, tm);
		else return query(pos, 2 * id + 1, tm + 1, tr);
	}
} st;

void solve() {
	Long n, q;
	cin >> n >> q;
	Long a[n], b[n];
	For(i, 0, n) cin >> a[i];
	For(i, 0, n) cin >> b[i];
	st.build(1, 0, n - 1);
	while (q--) {
		Long t;
		cin >> t;
		if (t == 1) {
			Long x, y, k;
			cin >> x >> y >> k;
			x--;
			y--;
			Long diff = x - y;
			st.update(y, y + k - 1, diff, 1, 0, n - 1);
		} else {
			Long pos;
			cin >> pos;
			pos--;
			Long add = st.query(pos, 1, 0, n - 1);
			if (add == INF) cout << b[pos] << endl;
			else cout << a[pos + add] << endl;
		}
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
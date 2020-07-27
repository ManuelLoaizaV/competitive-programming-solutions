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

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 1e6;
const Long INF = 1e15 + 1;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SegmentTree {
	Long tree[4 * N];
	void build(Long id, Long tl, Long tr) {
		if (tl == tr) {
			tree[id] = INF;
		} else {
			Long tm = (tl + tr) / 2;
			build(2 * id, tl, tm);
			build(2 * id + 1, tm + 1, tr);
			tree[id] = min(tree[2 * id], tree[2 * id + 1]);
		}
	}
	void update(Long pos, Long val, Long id, Long tl, Long tr) {
		if (tl == tr) {
			tree[id] = val;
		} else {
			Long tm = (tl + tr) / 2;
			if (pos <= tm) update(pos, val, 2 * id, tl, tm);
			else update(pos, val, 2 * id + 1, tm + 1, tr);
			tree[id] = min(tree[2 * id], tree[2 * id + 1]);
		}
	}
	Long query(Long l, Long r, Long id, Long tl, Long tr) {
		if (l <= tl and tr <= r) return tree[id];
		Long tm = (tl + tr) / 2;
		if (r <= tm) return query(l, r, 2 * id, tl, tm);
		if (tm < l) return query(l, r, 2 * id + 1, tm + 1, tr);
		return min(query(l, r, 2 * id, tl, tm), query(l, r, 2 * id + 1, tm + 1, tr));
	}
} st;

void solve() {
	Long n, m;
	cin >> n >> m;
	st.build(1, 0, n - 1);
	Long c[n];
	For(i, 0, n) cin >> c[i];
	For(i, 0, n) {
		if (i == 0) c[i] = 0;
		if (i > 0 and c[i] == 0) c[i] = INF;
	}
	Long dp[n];
	dp[n - 1] = 0;
	st.update(n - 1, 0LL, 1, 0, n - 1);
	roF(i, n - 2, 0) {
		Long l = min(i + 1, n - 1);
		Long r = min(i + m, n - 1);
		dp[i] = st.query(l, r, 1, 0, n - 1);
		dp[i] += c[i];
		if (dp[i] > INF) dp[i] = INF;
		st.update(i, dp[i], 1, 0, n - 1);
	}
	if (dp[0] >= INF) cout << "-1" << endl;
	else cout << dp[0] << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	For(i, 1, t + 1) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
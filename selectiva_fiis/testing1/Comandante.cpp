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

const int N = 2e5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SegmentTree {
	Pair tree[4 * N];
	Pair f(Pair a, Pair b) {
		if (a < b) return a;
		return b;
	}
	void build(vector<Long>& a, Long id, Long tl, Long tr) {
		if (tl == tr) {
			tree[id] = {a[tl], tl};
		} else {
			Long tm = (tl + tr) / 2;
			build(a, 2 * id, tl, tm);
			build(a, 2 * id + 1, tm + 1, tr);
			tree[id] = f(tree[2 * id], tree[2 * id + 1]);
		}
	}
	void update(Long pos, Long val, Long id, Long tl, Long tr) {
		if (tl == tr) {
			tree[id] = {val, tl};
		} else {
			Long tm = (tl + tr) / 2;
			if (pos <= tm) update(pos, val, 2 * id, tl, tm);
			else update(pos, val, 2 * id + 1, tm + 1, tr);
			tree[id] = f(tree[2 * id], tree[2 * id + 1]);
		}
	}
	Pair query(Long l, Long r, Long id, Long tl, Long tr) {
		if (l <= tl and tr <= r) return tree[id];
		Long tm = (tl + tr) / 2;
		if (r <= tm) return query(l, r, 2 * id, tl, tm);
		if (tm < l) return query(l, r, 2 * id + 1, tm + 1, tr);
		return f(query(l, r, 2 * id, tl, tm), query(l, r, 2 * id + 1, tm + 1, tr));
	}
} st;

void solve() {
	Long n;
	cin >> n;
	vector<Long> a(n);
	For(i, 0, n) cin >> a[i];
	st.build(a, 1, 0, n - 1);
	vector<Pair> answer;
	For(i, 0, n) {
		Pair next = st.query(i, n - 1, 1, 0, n - 1);
		if (a[i] == next.first) continue;
		answer.push_back({i, next.second});
		st.update(next.second, a[i], 1, 0, n - 1);
		swap(a[i], a[next.second]);
	}
	int size_answer = answer.size();
	cout << size_answer << endl;
	For(i, 0, size_answer) {
		int pos_i = answer[i].first + 1;
		int pos_j = answer[i].second + 1;
		cout << pos_i << " " << pos_j << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
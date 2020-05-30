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
vector<int> adj[N];
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct SegmentTree {
	int tree[4 * N];
	
	void build(vector<int> &a, int id, int tl, int tr) {
		if (tl == tr) {
			tree[id] = a[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(a, 2 * id, tl, tm);
			build(a, 2 * id + 1, tm + 1, tr);
			tree[id] = max(tree[2 * id], tree[2 * id + 1]);
		}
	}
	
	void update(int pos, int val, int id, int tl, int tr) {
		if (tl == tr) {
			tree[id] = val;
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) update(pos, val, 2 * id, tl, tm);
			else update(pos, val, 2 * id + 1, tm + 1, tr);
			tree[id] = max(tree[2 * id], tree[2 * id + 1]);
		}
	}
	
	int query(int l, int r, int id, int tl, int tr) {
		if (l <= tl and tr <= r) return tree[id];
		int tm = (tl + tr) / 2;
		if (r <= tm) return query(l, r, 2 * id, tl, tm);
		if (tm < l) return query(l, r, 2 * id + 1, tm + 1, tr);
		return max(query(l, r, 2 * id, tl, tm), query(l, r, 2 * id + 1, tm + 1, tr));
	}
};

struct HLD {
	SegmentTree st;
	int n, global_id;
	int parent[N], depth[N], tree_size[N], id[N], rt[N];

	int make_size(int u, int pu = -1, int d = 0) {
		parent[u] = pu;
		depth[u] = d;
		tree_size[u] = 1;
		for (int v : adj[u]) {
			if (v != pu) tree_size[u] += make_size(v, u, d + 1);
		}
		return tree_size[u];
	}

	void DFS(int u, int root = -1) {
		id[u] = global_id;
		global_id++;
		rt[u] = root;
		int w = 0;
		int w_size = -1;
		for (int v : adj[u]) {
			if (v != parent[u] and tree_size[v] > w_size) {
				w = v;
				w_size = tree_size[v];
			}
		}
		if (w) DFS(w, root);
		for (int v : adj[u]) if (v != parent[u] and v != w) DFS(v, v);
	}

	void modify(int u, int val) {
		st.update(id[u], val, 1, 0, n - 1);
	}

	int query(int u, int v) {
		int ans = -1;
		while (rt[u] != rt[v]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			ans = max(ans, st.query(id[rt[v]], id[v], 1, 0, n - 1));
			v = parent[rt[v]];
		}
		int a = id[u];
		int b = id[v];
		if (a > b) swap(a, b);
		ans = max(ans, st.query(a, b, 1, 0, n - 1));
		return ans;
	}

	void build(int _n) {
		n = _n;
		global_id = 0;
		make_size(0);
		DFS(0);
		vector<int> a(n, -1);
		st.build(a, 1, 0, n - 1);
	}
} hld;

struct Query {
	int u, v, milk, pos, ans;
};

bool incr_milk(Query &a, Query &b) {
	return a.milk < b.milk;
}

bool incr_pos(Query &a, Query &b) {
	return a.pos < b.pos;
}

void solve() {
	int n, q;
	cin >> n >> q;
	pair<int, int> farms[n];
	for (int i = 0; i < n; i++) {
		cin >> farms[i].first;
		farms[i].second = i;
	}	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	hld.build(n);
	Query queries[q];
	for (int i = 0; i < q; i++) {
		cin >> queries[i].u >> queries[i].v >> queries[i].milk;
		queries[i].u--;
		queries[i].v--;
		queries[i].pos = i;
		queries[i].ans = -1;
	}
	string ans = "";
	sort(queries, queries + q, incr_milk);
	sort(farms, farms + n);
	int cur_pos = 0;
	for (int i = 0; i < q; i++) {
		int cur_milk = queries[i].milk;
		while (cur_pos < n and farms[cur_pos].first <= cur_milk) {
			hld.modify(farms[cur_pos].second, farms[cur_pos].first);
			cur_pos++;
		}
		queries[i].ans = hld.query(queries[i].u, queries[i].v);
		//debug(queries[i].u, queries[i].v, queries[i].ans, queries[i].pos);
	}
	sort(queries, queries + q, incr_pos);
	for (int i = 0; i < q; i++) {
		if(queries[i].milk == queries[i].ans) ans += '1';
		else ans += '0';
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

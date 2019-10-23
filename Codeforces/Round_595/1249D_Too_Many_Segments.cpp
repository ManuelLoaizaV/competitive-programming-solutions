//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define l first
#define r second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 200005;
const int INF = 1e9;
const ld EPS = 10e-9;

struct Segment {
	int l;
	int r;
	int ind;
	bool operator < (const Segment &otro) const {
		if (l == otro.l) return r < otro.r;
		return l < otro.l;
	}
};

struct FenwickTree {
	int tree[N + 1];
	FenwickTree() { memset(tree, 0, sizeof(tree)); }
	void update(int i, int delta) {
		while (i <= N) {
			tree[i] += delta;
			i += (i & -i);
		}
	}
	int query(int i) {
		int ans = 0;
		while (i > 0) {
			ans += tree[i];
			i -= (i & -i);
		}
		return ans;
	}
};

struct Node {
	Segment s;
	int pos;
};

Node sentinel() {
	Node aux;
	aux.s.l = INF;
	aux.s.r = -INF;
	aux.s.ind = -1;
	aux.pos = -1;
	return aux;
}

struct SegmentTree {
	Node tree[4 * N];
	SegmentTree() { For(i,0,4*N) tree[i] = sentinel(); }
	Node comb(Node a, Node b) {
		if (a.s.r > b.s.r) return a;
		if (b.s.r > a.s.r) return b;
		if (a.s.l < b.s.l) return a;
		return b;
	}
	void build(Segment a[], int v, int tl, int tr) {
		if (tl == tr) {
			tree[v].s = a[tl];
			tree[v].pos = tl;
		} else {
			int tm = (tl + tr) / 2;
			build(a, 2 * v, tl, tm);
			build(a, 2 * v + 1, tm + 1, tr);
			tree[v] = comb(tree[2 * v], tree[2 * v + 1]);
		}
	}
	Node get_max(int v, int tl, int tr, int l, int r) {
		if (l > r) return sentinel();
		if (l == tl and r == tr) return tree[v];
		int tm = (tl + tr) / 2;
		return comb(get_max(2 * v, tl, tm, l, min(r, tm)),
					get_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));

	}
	void update(int v, int tl, int tr, int pos) {
		if (tl == tr) tree[v] = sentinel();
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) update(2 * v, tl, tm, pos);
			else update(2 * v + 1, tm + 1, tr, pos);
			tree[v] = comb(tree[2 * v], tree[2 * v + 1]);
		}
	}
};

// Busco el ultimo segmento que contenga al punto x
int search(Segment a[], int x, int n) {
	// TTTT
	if (a[n - 1].l <= x) return n - 1;
	// FFFF
	if (a[0].l > x) return -1;
	// TTFF
	int l = 0;
	int r = n - 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (a[m].l <= x) l = m;
		else r = m;
	}
	// TF
	if (a[r].r <= x) return r;
	return l;
}

int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	Segment segments[n];
	FenwickTree acc;
	SegmentTree st;
	For(i,0,n) {
		cin >> segments[i].l >> segments[i].r;
		segments[i].ind = i + 1;
		acc.update(segments[i].l, 1);
		acc.update(segments[i].r + 1, - 1);
	}
	sort(segments, segments + n);
	st.build(segments, 1, 0, n - 1);
	vi ans;
	For(i,1,200001) {
		//debug(i);
		int cur = acc.query(i);
		//debug(cur);
		while (cur > k) {
			int last = search(segments, i, n);
			//debug(last);
			Node del = st.get_max(1, 0, n - 1, 0, last);
			ans.pb(del.s.ind);
			acc.update(del.s.l, -1);
			acc.update(del.s.r + 1, 1);
			st.update(1, 0, n - 1, del.pos);
			cur--;
		}
	}
	int sz = ans.size();
	cout << sz << endl;
	For(i,0,sz) cout << ans[i] << " "; 
	return 0;
}

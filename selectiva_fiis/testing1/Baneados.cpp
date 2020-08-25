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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct Node {
	Long sum;
	bool lazy;
	Node* left;
	Node* right;
	Node() : sum(0LL), lazy(false), left(nullptr), right(nullptr) {}
	void push(Long tl, Long tr) {
		if (left == nullptr) {
			left = new Node();
			right = new Node();
		}
		if (lazy) {
			// Aplicar
			Long tm = (tl + tr) / 2;
			Long size_left = tm - tl + 1;
			Long size_right = tr - tm;
			left->sum = size_left;
			right->sum = size_right;
			// Propagar
			left->lazy = right->lazy = true;
			// Reiniciar
			lazy = false;
		}
	}
};

struct SegmentTree {
	Node* root;
	SegmentTree() { root = new Node(); }
	Long combine(Long x, Long y) { return x + y; }
	void update(Long l, Long r, Node* node, Long tl, Long tr) {
		if (r < tl or l > tr) return;
		if (l <= tl and tr <= r) {
			// Aplicar
			node->sum = tr - tl + 1LL;
			// Acumular
			node->lazy = true;

		} else {
			Long tm = (tl + tr) / 2;
			node->push(tl, tr);
			update(l, r, node->left, tl, tm);
			update(l, r, node->right, tm + 1, tr);
			node->sum = combine(node->left->sum, node->right->sum);
		}
	}
	Long query(Long l, Long r, Node* node, Long tl, Long tr) {
		if (l <= tl and tr <= r) return node->sum;
		Long tm = (tl + tr) / 2;
		node->push(tl, tr);
		if (r <= tm) return query(l, r, node->left, tl, tm);
		if (tm < l) return query(l, r, node->right, tm + 1, tr);
		return combine(query(l, r, node->left, tl, tm), query(l, r, node->right, tm + 1, tr));
	}
} st;

void solve() {
	Long n;
	cin >> n;
	Long queries;
	cin >> queries;
	while (queries--) {
		Long left, right;
		cin >> left >> right;
		st.update(left, right, st.root, 1LL, n);
	}
	Long answer = n - st.query(1, n, st.root, 1, n);
	cout << answer << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
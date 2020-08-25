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

vector<vector<int>> adj;
vector<int> componente;
vector<bool> used;
vector<int> representantes;
int componentes = 0;

void DFS(int u) {
	used[u] = true;
	componente[u] = componentes;
	for (int v : adj[u]) if (not used[v]) DFS(v);
}

void hallar_componentes(int n) {
	for (int i = 1; i <= n; i++) {
		if (not used[i]) {
			componentes++;
			DFS(i);
			representantes.push_back(i);
		}
	}
}

int l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> height;

void DFS_LCA(int u, int p, int h) {
	tin[u] = ++timer;
	up[u][0] = p;
	height[u] = h;
	for (int i = 1; i <= l; i++) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (int v : adj[u]) {
		if (v != p) DFS_LCA(v, u, h + 1);
	}
	tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] and tout[u] >= tout[v];
}
int lca(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (int i = l; i >= 0; i--) {
		if (not is_ancestor(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root, int n) {
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	DFS_LCA(root, root, 0);
}

void solve() {
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	componente.resize(n + 1);
	used.resize(n + 1);
	For(i, 0, n + 1) used[i] = false;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	hallar_componentes(n);
	for (int i = 0; i < componentes; i++) {
		int current = representantes[i];
		adj[0].push_back(current);
		adj[current].push_back(0);
	}
	height.resize(n + 1);
	preprocess(0, n + 1);
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (componente[u] != componente[v]) {
			cout << -1 << endl;
		} else {
			int anc = lca(u, v);
			int distance = height[u] + height[v] - 2 * height[anc];
			cout << distance % 2 << endl;
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
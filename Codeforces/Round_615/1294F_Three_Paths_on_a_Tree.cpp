// Gracias, Rodolfo
// Gracias, Roman
// Gracias, Maxi
// Gracias, MarcosK
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()
#define SZ(v) ((int)v.size())

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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int N = 2e5 + 5;
const ll INF = 1e18;
const ld EPS = 10e-9;

vector<int> adj[N];
int h[N], p[N];
bool used[N];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void DFS(int u, int anc) {
	used[u] = true;
	p[u] = anc;
	if (anc == -1) h[u] = 0;
	else h[u] = 1 + h[anc];
	//debug(u, p[u], h[u]);
	for (int v : adj[u]) {
		//debug(v, used[v]);
		if (not used[v]) DFS(v, u);
	}
} 

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> edges;
	For(i,0,n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		edges.pb({u, v});
		edges.pb({v, u});
	}
	int a, b, c;
	DFS(1, -1);
	int temp = -1;
	For(i,1,n+1) {
		if (h[i] > temp) {
			a = i;
			temp = h[i];
		}
	}
	For(i,1,n+1) {
		h[i] = 0;
		p[i] = 0;
		used[i] = false;
	}
	DFS(a, -1);
	int diametro = -1;
	For(i,1,n+1) {
		//debug(i, h[i]);
		if (h[i] > diametro) {
			b = i;
			diametro = h[i];
			//debug(b, diametro);
		}
	}
	int aux = b;
	set<pair<int, int>> ban;
	vector<int> nodes;
	while (p[aux] != -1) {
		//debug(aux, p[aux]);
		if (aux != a) nodes.pb(p[aux]);
		ban.insert({aux, p[aux]});
		ban.insert({p[aux], aux});
		aux = p[aux];
	}
	For(i,1,n+1) adj[i].clear();
	int sz = edges.size();
	For(i,0,sz) {
		if (ban.count(edges[i])) continue;
		int u = edges[i].ff;
		int v = edges[i].ss;
		//debug(u, v);
		adj[u].pb(v);
	}
	For(i,1,n+1) {
		h[i] = 0;
		p[i] = 0;
		used[i] = false;
	}
	used[a] = used[b] = true;
	h[a] = h[b] = -1;
	sz = nodes.size();
	//debug(nodes);
	For(i,0,sz) if (not used[nodes[i]]) DFS(nodes[i], -1);
	int maxi = -1;
	For(i,1,n+1) {
		//debug(i, h[i]);
		if (h[i] > maxi and i != a and i != b) {
			c = i;
			maxi = h[i];
		}
	}
	int ans = diametro + maxi;
	cout << ans << endl;
	cout << a << " " << b << " " << c << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
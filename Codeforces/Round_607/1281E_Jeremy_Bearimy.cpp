// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 2e5 + 5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int k, n;
ll G, B;
vector<pair<int, ll>> adj[N];
bool used[N];

void clean() {
	G = B = 0;
	For(i,0,n+1) {
		adj[i].clear();
		used[i] = false;
	}
}

int DFS(int u) {
	used[u] = true;
	int cnt = 1; // Acumulo nodos comenzando con u
	for (auto e : adj[u]) { // Para cada arista conectada a u
		int v = e.ff;
		ll t = e.ss;
		if (not used[v]) { // que no haya sido recorrida
			int add = DFS(v); // Cuenta nodos en ese subtree
			cnt += add; // Acumula los nodos del subtree al bajar via la arista e
			if (add % 2 != 0) G += t; // Si debajo de esta arista hay cantidad impar de nodos, necesariamente tengo que pasar por esta arista como minimo una vez
			B += t * min(n - add, add); // Maxima cantidad de veces que pasan por e
		}
	}
	return cnt; // Retorna la cantidad de nodos en el subtree que nace en u
}

void solve() {
	clean();
	cin >> k;
	n = 2 * k;
	For(i,0,n-1) {
		int a, b;
		ll t;
		cin >> a >> b >> t;
		adj[a].pb(mp(b, t));
		adj[b].pb(mp(a, t));
	}
	DFS(1);
	cout << G << " " << B << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

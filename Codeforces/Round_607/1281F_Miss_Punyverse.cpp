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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 3e3 + 5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int n, m, b[N], w[N], sz[N];
vi adj[N];
bool used[N];
ii dp[N][N], temp[N];
/*
dp[i][j] : (num, sum) Par obtenido al dividir el subarbol con raiz en i en j aldeas
num : max aldeas (distintas de i) donde #wasps > #bees
sum : max (#wasps - #bees) en el subarbol con raiz en i
*/

void init() {
	For(i,0,n) {
		used[i] = false;
		adj[i].clear();
	}
}

void DFS(int u) {
	used[u] = true;
	sz[u] = 1;
	dp[u][1] = mp(0, w[u] - b[u]); // (Aun no se procesan aldeas debajo, diferencia en el nodo)
	for (int v : adj[u]) {
		if (not used[v]) {
			DFS(v);
			int s = sz[u] + sz[v] + 1;
			For(i,0,s) temp[i] = mp(-1, 0LL);
			For(x,1,sz[u]+1) {
				For(y,1,sz[v]+1) {
					int z = x + y - 1;
					temp[z] = max(temp[z], {dp[u][x].ff + dp[v][y].ff, dp[u][x].ss + dp[v][y].ss});
					z = x + y;
					temp[z] = max(temp[z], {dp[u][x].ff + (dp[v][y].ff + (dp[v][y].ss > 0 ? 1 : 0)), dp[u][x].ss});
				}
			}
			For(i,0,s) dp[u][i] = temp[i];
			sz[u] += sz[v];
		}
	}
}

void solve() {
	cin >> n >> m;
	init();
	For(i,0,n) cin >> b[i];
	For(i,0,n) cin >> w[i];
	For(i,0,n-1) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	DFS(0);
	int ans = dp[0][m].ff + (dp[0][m].ss > 0);
	cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

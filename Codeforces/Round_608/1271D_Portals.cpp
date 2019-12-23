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

const int N = 5e3 + 5;
const ll INF = 1e8;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll n, m, k;
ll c[N][3], dp[N][N];
bool done[N][N];
vii adj[N];
//dp[i][j]: maxima importancia que se puede tener al llegar al castillo i con j soldados

bool decr(ii &a, ii &b) {
	if (a.ss == b.ss) return a.ff < b.ff;
	return a.ss > b.ss;
}

ll DP(ll i, ll j) {
	if (j < 0) return -INF;
	if (i == n) return 0LL;
	if (done[i][j]) return dp[i][j];
	done[i][j] = true;
	if (j < c[i][0]) dp[i][j] = -INF;
	else {
		ll _k = j + c[i][1]; // Recluto las personas en el castillo actual
		int sz = adj[i].size(); // Hallo priorizando
		// Primer caso, no defiendo ning[un castillo
		dp[i][j] = DP(i + 1, _k);
		// Sino, defiendo de los castillos en el orden de prioridad
		ll sum = 0LL;
		For(l,0,sz) {
			sum += adj[i][l].ss;
			dp[i][j] = max(dp[i][j], sum + DP(i + 1, _k - l - 1));
		}
	}
	return dp[i][j];
}


int main() {
	fastio;
	cin >> n >> m >> k;
	For(i,0,n) For(j,0,3) cin >> c[i][j];
	// Primero chequeare si es posible terminar de conquistar todos los castillos;
	ll aux = k;
	For(i,0,n) {
		if (aux >= c[i][0]) aux += c[i][1];
		else {
			cout << "-1" << endl;
			return 0;
		}
	}
	// Para cada castillo determinar[e la ultima posici[on en la cual este puede ser capturado
	int last[n];
	For(i,0,n) last[i] = i; // Por defecto, la ultima vez es cuando lo conquistas
	// Me quedar[e con el [ultimo castillo donde hay un portal a este
	For(i,0,m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		last[v] = max(last[v], u);
	}
	// Para cada ultima vez guardare de quien vino y cuanta importancia brinda
	For(i,0,n) adj[last[i]].pb(mp(i, c[i][2]));
	// En cada castillo, ordeno las importancias de mayor a menor
	For(i,0,n) sort(all(adj[i]), decr);
	ll ans = DP(0LL, k);
	cout << ans << endl;
	return 0;
}

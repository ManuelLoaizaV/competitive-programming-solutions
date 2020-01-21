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

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = 0LL;
	ii pos[k];
	For(i,0,k) cin >> pos[i].ff >> pos[i].ss;
	set<ll> uni;
	uni.insert(0LL);
	For(i,0,k) {
		uni.insert(pos[i].ff);
		uni.insert(pos[i].ss);
	}
	uni.insert(n);
	uni.insert(m);
	map<ll, ll> h;
	vi inv;
	for (auto it : uni) {
		int sz = h.size();
		h[it] = sz;
		inv.pb(it);
		//debug(it, h[it]);
	}
	int rows = h[n];
	int cols = h[m];
	bool cell[rows + 1][cols + 1];
	ll dp[rows + 1];
	For(i,0,rows+1) dp[i] = 0LL;
	For(i,0,rows+1) For(j,0,cols+1) cell[i][j] = false;
	For(i,0,k) {
		ll x = h[pos[i].ff];
		ll y = h[pos[i].ss];
		cell[x][y] = true;
	}

	ll add[rows + 1];
	For(j,1,cols+1) {
		For(i,0,rows+1) add[i] = 0LL;
		For(i,1,rows+1) {
			ll dx = inv[i] - inv[i - 1];
			ll dy = inv[j] - inv[j - 1];
			ll sum1 = dp[i - 1];
			ll sum2 = dp[i - 1] + add[i - 1];
			ll sum3 = dp[i];
			add[i] = add[i - 1];
			if (cell[i][j]) add[i]++;
			ll sum4 = dp[i] + add[i];
			if (sum1 & 1) ans += (dx - 1) * (dy - 1);
			if (sum2 & 1) ans += (dx - 1);
			if (sum3 & 1) ans += (dy - 1);
			if (sum4 & 1) ans++;
			//debug(i,j,ans);
		}
		For(i,0,rows+1) dp[i] += add[i];
	}
	cout << ans << " " << n * m - ans << endl;
}

int main() {
	freopen("dull.in", "r", stdin);
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
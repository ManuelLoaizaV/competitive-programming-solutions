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

typedef vector<vector<ld>> Matrix;
Matrix I(int n) {
	Matrix ans(n, vector<ld>(n));
	for (int i = 0; i < n; i++) ans[i][i] = 1;
	return ans;
}
Matrix operator * (Matrix &a, Matrix &b) {
	int n = a.size();
	int m = a[0].size();
	int p = b[0].size();
	Matrix ans(n, vector<ld>(p));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < m; k++)
				ans[i][j] += a[i][k] * b[k][j];
	return ans;
}
Matrix fast_pow(Matrix a, int b) {
	Matrix ans = I(a.size());
	while (b > 0) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;	
}

void solve() {
	ll n;
	int k;
	cin >> n >> k;
	bool cell[n][n];
	For(i,0,n) For(j,0,n) cin >> cell[i][j];
	ld ans = 0.0;
	ll den = 0LL;
	For(i,0,n) For(j,0,n) den += (n - i) * (n - j);
	pair<ld, ld> dp[n][n];
	int sz = ceil(n / 2.0);
	For(i,0,sz) {
		For(j,0,sz) {
			ll num = (i + 1LL) * (j + 1LL) * (n - i) * (n - j);
			ld p = (ld) num / den;
			Matrix markov(2, vector<ld>(2));
			For(q,0,2) For(r,0,2) markov[q][r] = (q != r ? p : 1 - p);
			markov = fast_pow(markov, k);
			dp[i][j].ff = markov[0][1];
			dp[i][j].ss = markov[1][1];
		}
	}
	For(i,0,sz) For(j,sz,n) dp[i][j] = dp[i][n - j - 1];
	For(i,sz,n) For(j,0,n) dp[i][j] = dp[n - i - 1][j];
	For(i,0,n) For(j,0,n) ans += (cell[i][j] ? dp[i][j].ss : dp[i][j].ff);
	cout << fixed << setprecision(5) << ans << endl;
}

int main() {
	freopen("fetiera.in", "r", stdin);
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}

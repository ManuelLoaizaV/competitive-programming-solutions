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

const int N = 1e3;
const Long INF = 1e6;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long dp[N][N][11][2];
bool done[N][N][11][2];
Long n, m, k;
string s, t;

// DP(i, j, k, l) : maxima suma de longitudes de substrings cuando nos falta concluir
// k substrings, en s[i ... n - 1], t[j ... m - 1] y hemos l-comenzado ya a analizar el ultimo substring
Long DP(Long i, Long j, Long rem, bool init) {
	if (rem == 0) return 0;
	if (i == n) {
		if (rem > 1) return -INF;
		// rem == 1
		if (init) return 0;
		return -INF;
	}
	if (j == m) {
		if (rem > 1) return -INF;
		// rem == 1
		if (init) return 0;
		return -INF;
	}
	if (done[i][j][rem][init]) return dp[i][j][rem][init];
	dp[i][j][rem][init] = 0;
	if (init) {
		if (s[i] == t[j]) {
			dp[i][j][rem][init] = max(dp[i][j][rem][init], 1 + DP(i + 1, j + 1, rem, true));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], 1 + DP(i + 1, j + 1, rem - 1, true));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i + 1, j, rem - 1, false));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i, j + 1, rem - 1, false));
		} else {
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i + 1, j, rem - 1, false));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i, j + 1, rem - 1, false));
		}
	} else {
		if (s[i] == t[j]) {
			dp[i][j][rem][init] = max(dp[i][j][rem][init], 1 + DP(i + 1, j + 1, rem, true));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i + 1, j, rem, false));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i, j + 1, rem, false));
		} else {
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i + 1, j, rem, false));
			dp[i][j][rem][init] = max(dp[i][j][rem][init], DP(i, j + 1, rem, false));
		}
	}
	done[i][j][rem][init] = true;
	return dp[i][j][rem][init];
}

void solve() {
	cin >> n >> m >> k;
	cin >> s >> t;
	cout << DP(0, 0, k, 0) << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
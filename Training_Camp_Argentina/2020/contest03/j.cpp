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

const int NN = 100;
const int N = 10;
const Long INF = 1e18;
const Double EPS = 10e-9;
const Long MOD = 1000000007;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long a[N];
Long dp[NN + 1][N];
bool done[NN + 1][N];
Long nCk[NN + 1][NN + 1];
Long n; // longitud del numero

void calcular_nCk() {
	For(i, 0, NN + 1) nCk[i][0] = 1LL;
	For(i, 0, NN + 1) {
		For(j, 1, i + 1) {
			nCk[i][j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % MOD;
		}
	}
}

Long DP(Long pos, Long digit) {
	Long sz = n - pos;
	if (pos == n) {
		For(d, digit, 10) if (a[d] > 0) return 0;
		return 1;
	}
	if (digit == 9) {
		if (sz < a[9]) return 0;
		else return 1;
	}
	if (done[pos][digit]) return dp[pos][digit];
	done[pos][digit] = true;
	dp[pos][digit] = 0LL;
	if (digit == 0) {
		for (Long used = a[0]; used <= sz; used++) {
			Long ways = (nCk[sz - 1][used] * DP(pos + used, 1)) % MOD;
			dp[pos][0] = (dp[pos][0] + ways) % MOD;
		}
	} else {
		for (Long used = a[digit]; used <= sz; used++) {
			Long ways = (nCk[sz][used] * DP(pos + used, digit + 1)) % MOD;
			dp[pos][digit] = (dp[pos][digit] + ways) % MOD;
		}
	}
	//debug(pos, digit, dp[pos][digit]);
	return dp[pos][digit];
}

void solve() {
	calcular_nCk();
	cin >> n;
	For(i, 0, N) cin >> a[i];
	Long ans = 0LL;
	For(i, 0, n) ans = (ans + DP(i, 0)) % MOD;
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
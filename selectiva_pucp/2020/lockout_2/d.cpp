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

const int N = 1e5 + 10;
const Long INF = 1e18;
const Double EPS = 10e-9;
const Long MOD = 1e9 + 7LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

void solve() {
	string s;
	cin >> s;
	Long sz = s.size();
	Long dp[sz][13];
	For(i, 0, sz) For(j, 0, 13) dp[i][j] = 0LL;
	if (s[sz - 1] == '?') {
		For(i, 0, 10) dp[sz - 1][i] = 1LL;
	} else {
		Long c = s[sz - 1] - '0';
		dp[sz - 1][c] = 1LL;
	}
	Long pot = 10LL;
	roF(pos, sz - 2, 0) {
		if (s[pos] == '?') {
			For(i, 0, 10) {
				Long cur = (i * pot) % 13LL;
				For(j, 0, 13) {
					Long to = (cur + j) % 13LL;
					dp[pos][to] = (dp[pos][to] + dp[pos + 1][j]) % MOD;
				}
			}
		} else {
			Long c = s[pos] - '0';
			Long cur = (c * pot) % 13LL;
			For(j, 0, 13) {
				Long to = (cur + j) % 13LL;
				dp[pos][to] = (dp[pos][to] + dp[pos + 1][j]) % MOD;
			}
		}
		pot = (pot * 10LL) % 13LL;
	}
	cout << dp[0][5] << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
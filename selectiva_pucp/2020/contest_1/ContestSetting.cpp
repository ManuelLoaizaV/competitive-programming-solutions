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
const long long MOD = 998244353LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<long long, long long> cnt;
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    vector<pair<long long, long long>> mens;
    std::map<long long, long long>::iterator it;
    for (it = cnt.begin(); it != cnt.end(); it++) {
        pair<long long, long long> men;
        men.first = it -> first;
        men.second = it -> second;
        mens.push_back(men);
    }
    int sz = mens.size();
    long long dp[k + 1][sz];
    for (int i = 0; i <= k; i++) for (int j = 0; j < sz; j++) dp[i][j] = 0LL;
    for (int i = 0; i < sz; i++) dp[0][i] = 1LL;
    dp[1][0] += mens[0].second;
    for (int j = 1; j < sz; j++) {
        for (int i = 1; i <= k; i++) {
            dp[i][j] = (dp[i][j - 1] + (mens[j].second * dp[i - 1][j - 1]) % MOD) % MOD;
            debug(i, j, dp[i][j]);
        }
    }
    long long ans = 0;
    //for (int i = 0; i < sz; i++) ans = (ans + dp[k][i]) % MOD;
    ans = dp[k][sz - 1];
    cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

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

const int N = 2e3 + 5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long suffix[N][26][2];
Long dp[N][N];
bool done[N][N];
string s, t;

Long DP(Long i, Long j) {
    if (i == -1) return 0;
    if (done[i][j]) return dp[i][j];
    if (i >= 0) {
        dp[i][j] = 1 + DP(i - 1, j);
        if (s[i] == t[j]) dp[i][j] = min(dp[i][j], DP(i - 1, j - 1));
    }
    int cur = t[j] - 'a';
    if (suffix[i + 1][cur][0] - suffix[j + 1][cur][1] > 0) dp[i][j] = min(dp[i][j], DP(i, j - 1));
    done[i][j] = true;
    //debug(i, j, dp[i][j]);
    return dp[i][j];
}

void solve() {
    Long n;
    cin >> n;
    cin >> s >> t;
    Long freq[2][26];
    memset(freq, 0, sizeof(freq));
    For(i,0,n) {
        freq[0][s[i] - 'a']++;
        freq[1][t[i] - 'a']++;
    }
    For(i,0,26) {
        if (freq[0][i] == freq[1][i]) continue;
        cout << -1 << endl;
        return;
    }
    For(i,0,26) For(j,0,2) suffix[n][i][j] = 0;
    roF(i,n-1,0) {
        For(j,0,26) For(k,0,2) suffix[i][j][k] = suffix[i + 1][j][k];
        suffix[i][s[i] - 'a'][0]++;
        suffix[i][t[i] - 'a'][1]++;
    }
    For(i,0,n+1) For(j,0,n+1) {
        dp[i][j] = INF;
        done[i][j] = false;
    }
    Long ans = DP(n - 1, n - 1);
    if (ans >= INF) cout << -1 << endl;
    cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define mt(a,b,c) mp(mp(a,b),c) 
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e5;
const ll INF = 1e18;
const ld EPS = 10e-9;
const ll MOD = 1000000007LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll dp[N + 1];

ll DP(ll i) {
	if (i < 0) return 0LL;
	if (i == 0) return 1LL;
	if (dp[i] != -1) return dp[i];
	dp[i] = 0;
	dp[i] = (DP(i - 1) % MOD + DP(i - 2) % MOD) % MOD;
	return dp[i];
}

int main() {
	fastio;
	For(i,0,N+1) dp[i] = -1;
	ll n, m;
	cin >> n >> m;
	ll ans = 0LL;
	ans = (DP(m) + DP(n)) % MOD;
	ans = (ans - 1LL + MOD) % MOD;
	ans = (ans * 2LL) % MOD;
	cout << ans << endl;
	return 0;
}

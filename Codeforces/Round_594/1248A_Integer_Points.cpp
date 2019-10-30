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

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n;
	cin >> n;
	int p[n];
	For(i,0,n) cin >> p[i];
	int m;
	cin >> m;
	int q[m];
	For(i,0,m) cin >> q[i];
	ll count[2][2];
	memset(count, 0, sizeof(count));
	For(i,0,n)
		if (p[i] % 2 == 0) count[0][0]++;
		else count[0][1]++;
	For(i,0,m)
		if (q[i] % 2 == 0) count[1][0]++;
		else count[1][1]++;
	ll answer = 0LL;
	answer = count[0][0] * count[1][0] + count[0][1] * count[1][1];
	cout << answer << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

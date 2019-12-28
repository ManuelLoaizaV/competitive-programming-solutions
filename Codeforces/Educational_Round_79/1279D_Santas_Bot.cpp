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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 2e6;
const ll INF = 1e18;
const ld EPS = 10e-9;
const ll MOD = 998244353LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll k[N];
vector<ll> who[N];

ll binPow(ll a, ll b) {
	if (b == 0) return 1LL;
	ll p = binPow(a, b / 2);
	if (b % 2 == 0) return ((p * p) % MOD);
	return ((((p * p) % MOD) * a) % MOD);
}

ll modInv(ll a, ll b) {
	return binPow(a, MOD - 2LL);
}

void solve() {
	ll n;
	cin >> n;
	For(i,1,n+1) {
		cin >> k[i];
		For(j,0,k[i]) {
			ll g;
			cin >> g;
			who[g].pb(i);
		}
	}
	ll num, den;
	num = 0LL;
	den = 1LL;
	For(i,1,1000001) {
		if (who[i].size() == 0) continue;
		ll sz = who[i].size();
		ll temp_num = sz;
		ll temp_den = (n * n) % MOD;
		ll sum_num = 0LL;
		ll sum_den = 1LL;
		For(j,0,sz) {
			ll _k = k[who[i][j]];
			sum_num = ((sum_num * _k) % MOD + sum_den) % MOD;
			sum_den = (sum_den * _k) % MOD;
		}
		temp_num = (temp_num * sum_num) % MOD;
		temp_den = (temp_den * sum_den) % MOD;
		num = ((num * temp_den) % MOD + (den * temp_num) % MOD) % MOD;
		den = (den * temp_den) % MOD;
	}
	ll ans = (num * modInv(den, MOD)) % MOD;
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

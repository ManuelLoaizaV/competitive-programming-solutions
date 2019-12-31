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
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e5;
const ll INF = 1e18;
const ld EPS = 10e-9;
const ll MOD = 1000000007LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll fact[N + 1];

ll binPow(ll a, ll b) {
	if (b == 0) return 1LL;
	ll p = binPow(a, b / 2);
	if (b % 2 == 0) return ((p * p) % MOD);
	return ((((p * p) % MOD) * a) % MOD);
}

ll modInv(ll a, ll b) { return binPow(a, MOD - 2LL); }

ll comb(ll n, ll k) { return ((fact[n] * modInv((fact[k] * fact[n - k]) % MOD, MOD)) % MOD); }

void solve() {
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	ll ans = 0LL;
	ll mini, maxi;
	ll a1, b1;
	a1 = b1 = 0LL;
	For(i,0,n) {
		if (a[i] == '1') a1++;
		if (b[i] == '1') b1++;
	}
	mini = abs(a1 - b1);
	if (a1 + b1 <= n) maxi = a1 + b1;
	else maxi = 2 * n - a1 - b1;
	for (ll i = mini; i <= maxi; i += 2) {
		ll temp = comb(n, i);
		ans = (ans + temp) % MOD;
	}
	cout << ans << endl;
}

int main() {
	fastio;
	fact[0] = fact[1] = 1LL;
	for (ll i = 2LL; i <= N; i++) fact[i] = (fact[i - 1] * i) % MOD;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

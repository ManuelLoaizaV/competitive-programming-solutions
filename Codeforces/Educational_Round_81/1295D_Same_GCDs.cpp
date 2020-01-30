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

ll LCM(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

ll calc(vector<ll> a, ll l, ll r) {
	ll ans = 0;
	int sz = a.size();
	int lim = 1 << sz;
	for (int mask = 1; mask < lim; mask++) {
		ll lcm = 1LL;
		ll bits = 0;
		bool ok = true;
		for (int i = 0; i < sz; i++) {
			if (mask & (1 << i)) {
				bits++;
				lcm = LCM(lcm, a[i]);
				if (lcm > r) {
					ok = false;
					break;
				}
			}
		}
		if (not ok) continue;
		ll cnt = r / lcm - (l - 1) / lcm;
		if (bits & 1) ans += cnt;
		else ans -= cnt;
	}
	return ans;
}

void solve() {
	ll a, m;
	cin >> a >> m;
	ll g = __gcd(a, m);
	ll l = a;
	ll r = a + m - 1LL;
	// Hallo los factores primos de m
	ll copy, aux;
	aux = copy = m / g;
	vector<ll> p;
	for (ll i = 2LL; i * i <= aux; i++) {
		if (copy % i == 0) {
			p.push_back(i);
			while (copy % i == 0) copy /= i;
		}
	}
	if (copy > 1) p.push_back(copy);
	// Quiero saber todos los multiplos del gcd con esos factores
	int sz_p = p.size();
	for (int i = 0; i < sz_p; i++) p[i] *= g;
	//debug(a, m, p, g);
	ll ans = r / g - (l - 1) / g - calc(p, l, r);
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
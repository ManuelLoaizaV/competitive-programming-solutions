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

void solve() {
	ll n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	ll cnt[2 * n][2];
	ll delta[2 * n];
	string t = s + s;
	if (s[0] == '0') {
		cnt[0][0] = 1;
		cnt[0][1] = 0;
	} else {
		cnt[0][0] = 0;
		cnt[0][1] = 1;
	}
	delta[0] = cnt[0][0] - cnt[0][1];
	for (int i = 1; i < 2 * n; i++) {
		for (int j = 0; j < 2; j++) cnt[i][j] = cnt[i - 1][j];
		if (t[i] == '0') cnt[i][0]++;
		else cnt[i][1]++;
		//debug(cnt[i][0], cnt[i][1]);
		delta[i] = cnt[i][0] - cnt[i][1];
	}
	ll ans = 0;
	ll d = delta[n] - delta[0];
	if (d == 0) {
		for (int i = 0; i < n; i++) {
			if (delta[i] == x) ans++;
		}
		if (ans > 0) ans = -1;
		if (x == 0 and ans == 0) ans++;
	} else {
		for (int i = 0; i < n; i++) {
			if (abs(x - delta[i]) % d == 0) {
				ll k = (x - delta[i]) / d;
				if (k >= 0) ans++;
			}
		}
		if (x == 0) ans++;
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
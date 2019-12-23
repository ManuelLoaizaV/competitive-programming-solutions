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

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;
const ll MOD = 1e9 + 7LL;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	ll x;
	string s;
	cin >> x >> s;
	ll sz = s.size();
	ll ans = sz;
	string aux = s;
	int pos = 0;
	bool ok = false;
	while (aux.size() < x) {
		int temp = aux.size();
		For(i,0,aux[pos] - '1') {
			For(j,pos+1,temp) {
				aux += aux[j];
				if (aux.size() == x) {
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) break;
		pos++;
	}
	s = aux;
	For(i,0,x) {
		ll temp = (ans - (ll)(i + 1) + MOD) % MOD;
		ans = (ans + (ll) (s[i] - '0' - 1LL) * temp) % MOD;
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

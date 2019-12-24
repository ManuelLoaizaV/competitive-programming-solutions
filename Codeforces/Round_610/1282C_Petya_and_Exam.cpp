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
#define For(i,a,b) for (ll i = a; i < b; i++)
#define roF(i,a,b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int N = 6e5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ii p[N], freq[N];
ll n, T, a, b, unos, ceros;
map<ll, ll> h, inv;
set<ll> uni;

// 0 : easy
// 1 : hard

ll search(int ind) {
	ll ans = 0;
	ll t = inv[ind];
	ll cost = freq[ind].ff * a + freq[ind].ss * b;
	if (cost > t) return 0;
	ans += freq[ind].ff + freq[ind].ss;
	//debug(cost);
	//debug(ans);
	ll c = ceros - freq[ind].ff;
	ll u = unos - freq[ind].ss;
	//debug(c);
	//debug(u);
	if (c > 0) {
		ll l, r;
		l = 0;
		r = c;
		bool go = false;
		if (cost + r * a <= t) {
			cost += r * a;
			ans += r;
			go = true;
		}
		if (not go) {
			while (r - l > 1) {
				ll m = (l + r) / 2;
				if (cost + a * m <= t) l = m;
				else r = m;
			}
			if (cost + a * r <= t) {
				ans += r;
				cost += a * r;
			} else {
				ans += l;
				cost += a * l;
			}
		}
	}
	//debug(cost);
	//debug(ans);
	if (u > 0) {
		ll l, r;
		l = 0;
		r = u;
		bool go = false;
		if (cost + r * b <= t) {
			cost += r * b;
			ans += r;
			go = true;
		}
		if (not go) {
			while (r - l > 1) {
				ll m = (l + r) / 2;
				if (cost + b * m <= t) l = m;
				else r = m;
			}
			if (cost + b * r <= t) ans += r;
			else ans += l;
		}
	}
	//debug(cost);
	//debug(ans);
	return ans;
}

void solve() {
	h.clear();
	inv.clear();
	uni.clear();
	cin >> n >> T >> a >> b;
	For(i,0,n) cin >> p[i].ff;
	For(i,0,n) cin >> p[i].ss;
	unos = ceros = 0;
	For(i,0,n) {
		if (p[i].ff == 0) ceros++;
		else unos++;
	}
	// Guardo todos los tiempos a analizar
	uni.insert(-1);
	uni.insert(0);
	uni.insert(T);
	uni.insert(T - 1);
	For(i,0,n) {
		uni.insert(p[i].ss);
		uni.insert(p[i].ss - 1);
	}
	vi t;
	std::set<ll>::iterator it;
	for (it = uni.begin(); it != uni.end(); it++) t.pb(*it);
	sort(all(t));
	ll sz = t.size();
	// Limpio lo anterior;
	For(i,0,sz) freq[i] = mp(0LL, 0LL);
	For(i,0,sz) {
		h[t[i]] = i;
		inv[i] = t[i];
	}
	For(i,0,n) {
		if (p[i].ff == 0) freq[h[p[i].ss]].ff++;
		else freq[h[p[i].ss]].ss++;
	}
	// Acumulo la cantidad de problemas obligatorios para cada tiempo valido
	For(i,1,sz) freq[i] = {freq[i - 1].ff + freq[i].ff, freq[i - 1].ss + freq[i].ss};
	// Para cada tiempo valido, hallo lo maximo que puedo resolver
	ll ans = 0LL;
	For(i,0,sz) {
		//debug(i);
		//debug(inv[i]);
		ll temp = search(i);
		//debug(temp);
		ans = max(ans, temp);
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

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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

struct Interval {
	ll l, r, tl, tr;
	int prev, next;
	Interval(){}
	Interval(ll _l, ll _r, ll _tl, ll _tr) {
		l = _l;
		r = _r;
		tl = _tl;
		tr = _tr;
	}
	ll cost(ll x) { return min(abs(x - tl), abs(x - tr)); }
};

void solve() {
	int n, m;
	cin >> n >> m;
	ll x[n];
	For(i,0,n) cin >> x[i];
	sort(x, x + n);
	vector<Interval> inter;
	// Creo los intervalos
	inter.pb(Interval(-INF, x[0] - 1, x[0], x[0]));
	For(i,0,n-1) {
		Interval aux(x[i] + 1, x[i + 1] - 1, x[i], x[i + 1]);
		if (aux.l <= aux.r) inter.pb(aux);
	}
	inter.pb(Interval(x[n - 1] + 1, INF, x[n - 1], x[n - 1]));
	// Los linkeo con el anterior y posterior
	int sz = inter.size();
	For(i,0,sz) {
		inter[i].prev = (i - 1 + sz) % sz;
		inter[i].next = (i + 1) % sz;
	}
	ll sum = 0LL;
	vector<ll> ans;
	int pos = 0;
	bool first = true;
	For(i,0,m) {
		if (pos == 0) {
			sum += inter[0].cost(inter[0].r);
			ans.pb(inter[0].r);
			inter[0].r--;
			pos = inter[0].next;
			continue;
		}
		if (pos == sz - 1) {
			sum += inter[sz - 1].cost(inter[sz - 1].l);
			ans.pb(inter[sz - 1].l);
			inter[sz - 1].l++;
			pos = inter[sz - 1].next;
			continue;
		}
		// En un intervalo intermedio
		if (first) {
			sum += inter[pos].cost(inter[pos].l);
			ans.pb(inter[pos].l);
			inter[pos].l++;
			first = false;
			// Si el intervalo sigue siendo valido
			if (inter[pos].l <= inter[pos].r) continue;
			// Sino es valido, lo elimino
			inter[inter[pos].prev].next = inter[pos].next;
			inter[inter[pos].next].prev = inter[pos].prev;
			pos = inter[pos].next;
			first = true;
		} else {
			sum += inter[pos].cost(inter[pos].r);
			ans.pb(inter[pos].r);
			inter[pos].r--;
			first = true;
			// Si el intervalo sigue siendo valido
			if (inter[pos].l <= inter[pos].r) {
				pos = inter[pos].next;
				continue;
			}
			// Sino es valido, lo elimino
			inter[inter[pos].prev].next = inter[pos].next;
			inter[inter[pos].next].prev = inter[pos].prev;
			pos = inter[pos].next;
			first = true;
		}
	}
	cout << sum << endl;
	For(i,0,m) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

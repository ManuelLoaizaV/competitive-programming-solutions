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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 2e5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ii salary[N];

bool comp1(ii &a, ii &b) { return a.ff < b.ff; }
bool comp2(ii &a, ii &b) { return a.ss < b.ss; }

bool check(ll m, int n, ll s) {
	ll monto = 0LL;
	int izq, der;
	izq = der = 0;
	vii problema;
	For(i,0,n) {
		if (salary[i].ss < m) {
			monto += salary[i].ff;
			izq++;
			continue;
		}
		if (salary[i].ff > m) {
			monto += salary[i].ff;
			der++;
			continue;
		}
		problema.pb(salary[i]);
	}
	if (izq > (n - 1) / 2) return false;
	if (der > (n - 1) / 2) return false;
	// De los que no fueron escogidos, necesito tantos mayores o iguales a m
	// Entonces a ellos los escojo como m y a los demas com su minimo
	sort(all(problema), comp1);
	int necesito = (n + 1) / 2 - der;
	monto += ((ll)necesito * m);
	int sz = problema.size();
	For(i,0,sz-necesito) monto += problema[i].ff;
	if (monto <= s) return true;
	return false;
}

void solve() {
	int n;
	ll s;
	cin >> n >> s;
	For(i,0,n) cin >> salary[i].ff >> salary[i].ss;
	ll l, r;
	sort(salary, salary + n, comp1);
	l = salary[(n - 1) / 2].ff;
	sort(salary, salary + n, comp2);
	r = salary[(n - 1) / 2].ss;
	// FFFFF nunca ocurre ya que garantizan puede pagar minimo a todos
	// TTTTT
	//debug(l);
	//debug(r);
	if (check(r, n, s)) {
		cout << r << endl;
		return;
	}
	while (r - l > 1LL) {
		ll m = (l + r) / 2;
		//debug(l);
		//debug(r);
		//debug(m);
		if (check(m, n, s)) l = m;
		else r = m;
	}
	// TF
	if (check(r, n, s)) cout << r << endl;
	else cout << l << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

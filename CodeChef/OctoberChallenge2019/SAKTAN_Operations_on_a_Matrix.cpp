#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i =a ; i >= b; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int  N = 1e5;
const ll INF = 1e18;
const ld EPS = 1e-9;

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vii queries;
	set<int> r_u, c_u;
	For(i,0,q) {
		ii aux;
		cin >> aux.x >> aux.y;
		queries.pb(aux);
		r_u.insert(aux.x);
		c_u.insert(aux.y);
	}
	std::set<int>::iterator it;
	vi r, c;
	for (it = r_u.begin(); it != r_u.end(); it++) r.pb((*it));
	for (it = c_u.begin(); it != c_u.end(); it++) c.pb((*it));
	sort(r.begin(), r.end());
	sort(c.begin(), c.end());
	int sz_r = r.size();
	int sz_c = c.size();
	int count_r[sz_r], count_c[sz_c];
	memset(count_r, 0, sizeof(count_r));
	memset(count_c, 0, sizeof(count_c));
	map<int, int> h_r, h_c;
	For(i,0,sz_r) h_r[r[i]] = i;
	For(i,0,sz_c) h_c[c[i]] = i;
	// Procesare las queries
	int odd = 0; // cantidad de filas 
	For(i,0,q) {
		int _r = h_r[queries[i].x];
		int _c = h_c[queries[i].y];
		count_c[_c]++;
		count_r[_r]++;
		if (count_r[_r] % 2 == 0) odd--;
		else odd++;
	}
	ll ans = 0LL;
	if (sz_c == 1) {
		// Se le aniade antes del inicio
		ans += (odd * (c[0] - 1));
		// El medio
		int _c = h_c[c[0]];
		if (count_c[_c] % 2 == 0) ans += odd;
		else ans += (n - odd);
	} else {
		// Se le aniade antes del inicio
		ans += (odd * (c[0] - 1));
		// El medio
		int _c = h_c[c[0]];
		if (count_c[_c] % 2 == 0) ans += odd;
		else ans += (n - odd);
		For(i,1,sz_c) {
			// Entre el actual y el anterior
			ans += (c[i] - c[i - 1] - 1) * odd;
			// El medio
			_c = h_c[c[i]];
			if (count_c[_c] % 2 == 0) ans += odd;
			else ans += (n - odd);
		}
	}
	// Se le aniade la cola
	ans += (odd * (m - c[sz_c - 1]));
	cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

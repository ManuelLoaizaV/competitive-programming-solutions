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

const int N = 1000005;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int tree[N + 1];

void update(int i, ll delta) {
	while (i <= N) {
		tree[i] += delta;
		i += (i & -i);
	}
}

ll query(int i) {
	ll sum = 0LL;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

void solve() {
	int n;
	cin >> n;
	vector<int> s[n];
	bool crec[n];
	ll add = 0LL; // numero de crecientes
	For(i,0,n) crec[i] = false;
	For(i,0,n) {
		int sz;
		cin >> sz;
		For(j,0,sz) {
			int x;
			cin >> x;
			x++;
			s[i].pb(x);
		}
		// Determino si es creciente
		For(j,0,sz-1) {
			if (s[i][j] < s[i][j + 1]) {
				crec[i] = true;
				add++;
				break;
			}
		}
		// updateo
		if (not crec[i]) update(s[i][0], 1LL);
	}
	ll ans = 0LL;
	For(i,0,n) {
		if (crec[i]) ans += n;
		else {
			ans += add;
			int sz = s[i].size();
			ans += query(1000002) - query(s[i][sz - 1]);
		}
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

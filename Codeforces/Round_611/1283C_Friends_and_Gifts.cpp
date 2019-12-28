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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n;
	cin >> n;
	int f[n], ans[n];
	For(i,0,n) cin >> f[i];
	For(i,0,n) ans[i] = f[i];
	bool recibe[n + 1];
	For(i,0,n+1) recibe[i] = false;
	For(i,0,n) recibe[f[i]] = true;
	deque<int> pendiente;
	For(i,1,n+1) if (not recibe[i]) pendiente.pb(i);
	vi analizar;
	For(i,0,n) if (not recibe[i + 1] and f[i] == 0) analizar.pb(i);
	For(i,0,n) if (recibe[i + 1] and f[i] == 0) analizar.pb(i);
	int len = analizar.size();
	For(i,0,len) {
		int x = analizar[i];
		if (pendiente[0] != x + 1) {
			ans[x] = pendiente[0];
			pendiente.pop_front();
		} else {
			int sz = pendiente.size();
			ans[x] = pendiente[sz - 1];
			pendiente.pop_back();
		}
	}
	For(i,0,n) {
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

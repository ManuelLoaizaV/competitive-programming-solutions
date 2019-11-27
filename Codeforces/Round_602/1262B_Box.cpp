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

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n;
	cin >> n;
	int p[n];
	For(i,0,n) cin >> p[i];
	For(i,0,n) {
		if (p[i] >= i + 1) continue;
		cout << "-1" << endl;
		return;
	}
	bool used[n + 1];
	For(i,0,n+1) used[i] = false;
	int ans[n];
	For(i,0,n) ans[i] = -1;
	ans[0] = p[0];
	used[p[0]] = true;
	For(i,1,n) {
		if (p[i] != p[i - 1]) {
			used[p[i]] = true;
			ans[i] = p[i];
		}
	}
	vi faltan;
	For(i,1,n+1) if (not used[i]) faltan.pb(i);
	int j = 0;
	For(i,0,n) if (ans[i] == -1) ans[i] = faltan[j++];
	For(i,0,n)
		if (i == 0) cout << ans[i];
		else cout << " " << ans[i];
	cout << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

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
const int INF = 1e9;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n;
	cin >> n;
	int a[n];
	For(i,0,n) cin >> a[i];
	if (n == 1) {
		cout << "-1" << endl;
		return;
	}
	// Si hay dos consecutivos, esa es la respuesta
	int pos[n + 1];
	For(i,0,n+1) pos[i] = -1;
	int ans = INF;
	For(i,0,n) {
		if (pos[a[i]] == -1) pos[a[i]] = i;
		else {
			int temp = i - pos[a[i]] + 1;
			ans = min(ans, temp);
			pos[a[i]] = i;
		}
	}
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

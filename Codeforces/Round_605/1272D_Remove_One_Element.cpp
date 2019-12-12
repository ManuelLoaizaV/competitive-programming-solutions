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

ll dp_l[N], dp_r[N];

int main() {
	fastio;
	int n;
	cin >> n;
	ll a[n + 2];
	a[0] = INF;
	a[n + 1] = -INF;
	For(i,1,n+1) cin >> a[i];
	dp_l[0] = dp_l[n + 1] = 1;
	dp_r[0] = dp_r[n + 1] = 1;
	For(i,1,n+1) {
		if (a[i - 1] < a[i]) dp_l[i] = dp_l[i - 1] + 1;
		else dp_l[i] = 1;
	}
	roF(i,n,1) {
		if (a[i] < a[i + 1]) dp_r[i] = dp_r[i + 1] + 1;
		else dp_r[i] = 1;
	}
	ll ans = 0LL;
	For(i,0,n+2) ans = max(ans, dp_l[i]);
	For(i,0,n+2) ans = max(ans, dp_r[i]);
	For(i,1,n+1) {
		if (a[i - 1] < a[i + 1]) {
			ll temp = dp_l[i - 1] + dp_r[i + 1];
			ans = max(ans, temp);
		}
	}
	cout << ans << endl;
	return 0;
}

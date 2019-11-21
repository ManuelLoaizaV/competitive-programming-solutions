// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

ll sum[N], a[N];
vi pos;

ll search(ll l, ll r, ll x) {
	// FFFF
	if (pos[l] > x) return -1;
	// TTTT
	if (pos[r] <= x) return r;
	// TTFF
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (pos[m] <= x) l = m;
		else r = m;
	}
	// TF
	if (pos[r] <= x) return r;
	return l;
}

int main() {
	fastio;
	int n;
	cin >> n;
	For(i,0,n) cin >> a[i];
	For(i,0,n) if (a[i] == 1) pos.pb(i);
	int ones = pos.size();
	if (ones == 1) {
		cout << "-1" << endl;
		return 0;
	}
	vi div;
	For(i,2,ones+1) if (ones % i == 0) div.pb(i);
	int sz = div.size();
	sum[0] = pos[0];
	For(i,1,ones) sum[i] = sum[i - 1] + pos[i];
	sum[n] = sum[n - 1];
	ll ans = INF;
	For(i,0,sz) {
		ll k = div[i];
		//debug(k);
		ll count = ones / k;
		ll total = 0LL;
		For(j,0,count) {
			ll l = j * k;
			ll r = (j + 1) * k - 1;
			ll block = INF;
			For(x,pos[l],pos[r]+1) {
				//debug(x);
				ll m = search(l, r, x);
				//debug(m);
				ll ind = m - l + 1;
				//debug(ind);
				ll sum1 = sum[m] - (l == 0 ? 0LL : sum[l - 1]);
				ll sum2 = sum[r] - sum[m];
				ll temp = sum2 - sum1 + (2 * ind - k) * x;
				//debug(sum1);
				//debug(sum2);
				//debug(temp);
				//debug(block);
				block = min(block, temp);
				//debug(block);
			}
			total += block;
			//debug(total);
		}
		ans = min(ans, total);
		//debug(ans);
	}
	cout << ans << endl;
	return 0;
}

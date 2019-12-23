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

ll n, k;

bool count_even(ll x) {
	ll sum = 0LL;
	ll pot = 1;
	ll aux = x;
	while (aux <= n) {
		aux *= 2LL;
		pot *= 2LL;
		sum += pot;
	}
	sum -= pot;
	aux /= 2;
	ll l = aux;
	ll r = min(n, aux + pot - 1);
	sum += (r - l + 1LL);
	return sum >= k;
}

bool count_odd(ll x) {
	ll sum = 0LL;
	ll pot = 1LL;
	ll aux = x;
	while (aux <= n) {
		aux *= 2LL;
		sum += pot;
		pot *= 2;
	}
	aux /= 2;
	pot /= 2;
	sum -= pot;
	ll l = aux;
	ll r = min(n, aux + pot - 1);
	sum += (r - l + 1LL);
	return sum >= k;
}

ll even(ll l, ll r) {
	//cout << "EVEN" << endl;
	if (not count_even(l)) return -1;
	if (count_even(r)) return r;
	while (r - l > 2) {
		ll m = (l + r) / 2;
		//debug(m);
		if (m % 2 != 0) {
			if (l <= m - 1 and m - 1 <= r) m--;
			else m++;
		}
		if (count_even(m)) l = m;
		else r = m;
	}
	//debug(r);
	if (count_even(r)) return r;
	//debug(l);
	return l;
} 

ll odd(ll l, ll r) {
	//cout << "ODD" << endl;
	if (not count_odd(l)) return -1;
	if (count_odd(r)) return r;
	while (r - l > 2) {
		ll m = (l + r) / 2;
		//debug(m);
		if (m % 2 == 0) {
			if (l <= m - 1 and m - 1 <= r) m--;
			else m++;
		}
		if (count_odd(m)) l = m;
		else r = m;
	}
	//debug(r);
	if (count_odd(r)) return r;
	//debug(l);
	return l;
}

int main() {
	fastio;
	cin >> n >> k;
	if (n == 1) cout << 1 << endl;
	else {
		ll ans = max(even(2, (n % 2 == 0 ? n : (n - 1))), odd(1, (n % 2 == 0 ? (n - 1) : n)));
		cout << ans << endl;
	}
	return 0;
}
